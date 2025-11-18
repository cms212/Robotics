// Minimal behavior tree that queries the `is_centered` service repeatedly
// and finishes the single stage when the service returns X == 0 (float32).

#include <chrono>
#include <thread>
#include <memory>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "ros_interfaces/srv/centered.hpp"

#include "behaviortree_cpp_v3/bt_factory.h"

using namespace std::chrono_literals;

static const char* xml_text = R"(
<root BTCPP_format="4">
    <BehaviorTree ID="MainTree">
        <IsCentered name="IsCentered"/>
    </BehaviorTree>
</root>
 )";

// Global ROS node used by the BT node to create a client and be spun in a background executor.
static std::shared_ptr<rclcpp::Node> g_ros_node = nullptr;

class IsCenteredNode : public BT::CoroActionNode
{
public:
    IsCenteredNode(const std::string & name, const BT::NodeConfiguration & config)
    : BT::CoroActionNode(name, config)
    {
        if (!g_ros_node) {
            throw std::runtime_error("Global ROS node not initialized");
        }
        client_ = g_ros_node->create_client<ros_interfaces::srv::Centered>("is_centered");
        // Don't block forever here — the tick loop will handle retries.
        if (!client_->wait_for_service(1s)) {
            RCLCPP_WARN(g_ros_node->get_logger(), "is_centered service not available yet");
        }
    }

    static BT::PortsList providedPorts() { return {}; }

    BT::NodeStatus tick() override
    {
        // Loop until the service returns X == 0 or we are halted.
        while (rclcpp::ok()) {
            if (!client_->service_is_ready()) {
                // Service is not ready yet; yield and let the tree tick again later.
                setStatusRunningAndYield();
                continue;
            }

            auto request = std::make_shared<ros_interfaces::srv::Centered::Request>();
            auto future = client_->async_send_request(request);

            // Poll the future in small intervals so we can yield cooperatively.
            for (;;) {
                // If the node was halted, exit with FAILURE.
                if (isHalted()) {
                    return BT::NodeStatus::FAILURE;
                }

                // Check if the response is ready.
                if (future.wait_for(50ms) == std::future_status::ready) {
                    auto res = future.get();
                    float X = res->X; // service is float32
                    RCLCPP_INFO(g_ros_node->get_logger(), "IsCentered service responded X=%.6f", static_cast<double>(X));
                    if (X == 0.0f) {
                        return BT::NodeStatus::SUCCESS;
                    }
                    // Not centered yet — report RUNNING and yield so the tree can do other work or be re-ticked.
                    setStatusRunningAndYield();
                    break; // break polling loop to send another request on next iteration
                }

                // Not ready, yield so other BT activity or interrupts can run.
                setStatusRunningAndYield();
            }
        }
        return BT::NodeStatus::FAILURE;
    }

    void halt() override
    {
        // Let the base class record the halt and propagate.
        CoroActionNode::halt();
    }

private:
    rclcpp::Client<ros_interfaces::srv::Centered>::SharedPtr client_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    // Create a ROS node that the BT nodes can use for clients.
    g_ros_node = rclcpp::Node::make_shared("bt_center_client_node");

    // Spin the ROS node in a background thread so service responses are processed.
    rclcpp::executors::SingleThreadedExecutor exec;
    exec.add_node(g_ros_node);
    std::thread spin_thread([&exec]() {
        exec.spin();
    });

    // Create factory and register the Coro action node.
    BT::BehaviorTreeFactory factory;
    factory.registerNodeType<IsCenteredNode>("IsCentered");

    // Create the tree from the small xml above.
    auto tree = factory.createTreeFromText(xml_text);

    // Tick the tree until SUCCESS or FAILURE.
    while (rclcpp::ok()) {
        auto status = tree.tickRoot();
        if (status == BT::NodeStatus::SUCCESS) {
            std::cout << "Behavior tree: stage succeeded (centered).\n";
            break;
        }
        if (status == BT::NodeStatus::FAILURE) {
            std::cout << "Behavior tree: stage failed.\n";
            break;
        }
        // Sleep a short while before the next tick.
        std::this_thread::sleep_for(100ms);
    }

    // Shutdown ROS and join spinner thread.
    rclcpp::shutdown();
    if (spin_thread.joinable()) spin_thread.join();
    return 0;
}