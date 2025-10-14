#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/tennis_ball_detection.hpp"



class DetectionInfoSubscriber : public rclcpp::Node
{
public:
    DetectionInfoSubscriber()
    : Node("detection_info_subscriber")
    {
        auto topic_callback =
        [this](message_interfaces::msg::TennisBallDetection::UniquePtr msg) -> void {
            RCLCPP_INFO(this->get_logger(), "I heard: 'left_x:%d /n right_x:%d /n top_y:%d /n bottom_y:%d'", msg->left_x, msg->right_x, msg->top_y, msg->bottom_y);
        };

        auto distance_processing_callback =
        [this](message_interfaces::msg::TennisBallDetection::UniquePtr msg) -> void {
            float r = 
            x = processX(*msg, r);
            y = processY(*msg, r);
            z = processZ(*msg, r);
            RCLCPP_INFO(this->get_logger(), "x: %f, y: %f, z: %f", x, y, z);
        };

        detection_info_subscription =
        this->create_subscription<message_interfaces::msg::TennisBallDetection>("detection_info", 5, topic_callback);
    }

private:
    rclcpp::Subscription<message_interfaces::msg::TennisBallDetection>::SharedPtr detection_info_subscription;
    private float camera_fov = 70.42;
    private float tennis_ball_width =  .067; // meters
    private float x;
    private float y;
    private float z;
    private float processX(const message_interfaces::msg::TennisBallDetection::UniquePtr &msg, float r){

    }
    private float processY(const message_interfaces::msg::TennisBallDetection::UniquePtr &msg, float r){

    }
    private float processZ(const message_interfaces::msg::TennisBallDetection::UniquePtr &msg, float r){

    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DetectionInfoSubscriber>());
    rclcpp::shutdown();
    return 0;
}