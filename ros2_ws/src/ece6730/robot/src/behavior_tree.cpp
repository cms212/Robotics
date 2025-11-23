// Minimal behavior tree that queries the `centered` service repeatedly
// and finishes the single stage when the service returns X within [-0.25, 0.25] range.

#include <chrono>
#include <thread>
#include <memory>
#include <iostream>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "ros_interfaces/srv/centered.hpp"
#include "ros_interfaces/srv/forward.hpp"
#include "message_interfaces/msg/arduino_command.hpp"
#include "behaviortree_cpp/bt_factory.h"

using namespace std::chrono_literals;

using namespace BT;

static const char* xml_text = R"(
<root BTCPP_format="4">
  <BehaviorTree ID="MainTree">
    <Sequence name="root_sequence">
      <IsCentered name="IsCentered"/>
      <IsForwarded name="IsForwarded"/>
    </Sequence>
  </BehaviorTree>
</root>
 )";

// --- StatefulActionNode that calls the `centered` service
class IsCentered : public StatefulActionNode
{
public:
  IsCentered(const std::string &name, const NodeConfiguration &config)
    : StatefulActionNode(name, config)
  {
    node_ = std::make_shared<rclcpp::Node>("is_centered_client");
    client_ = node_->create_client<ros_interfaces::srv::Centered>("centered");
    // create publisher here so it's always valid before onRunning() may publish
    arduino_command_publisher_ = node_->create_publisher<message_interfaces::msg::ArduinoCommand>("arduino_command", 10);
  }

  static PortsList providedPorts()
  {
    return {};
  }

  NodeStatus onStart() override
  {
    // if service not available yet, stay RUNNING
    if (!client_->wait_for_service(500ms)) {
      RCLCPP_INFO(node_->get_logger(), "centered service not available yet");
      return NodeStatus::RUNNING;
    }

    // send request and mark deadline
    auto request = std::make_shared<ros_interfaces::srv::Centered::Request>();
    future_ = client_->async_send_request(request);
    deadline_ = std::chrono::steady_clock::now() + 1s;
    return NodeStatus::RUNNING;
  }

  NodeStatus onRunning() override
  {
    rclcpp::spin_some(node_);

    if (!future_.valid()) {
      // send a request if none pending
      auto request = std::make_shared<ros_interfaces::srv::Centered::Request>();
      future_ = client_->async_send_request(request);
      deadline_ = std::chrono::steady_clock::now() + 1s;
      return NodeStatus::RUNNING;
    }

    // if response not ready yet
    if (future_.wait_for(std::chrono::milliseconds(0)) != std::future_status::ready) {
      if (std::chrono::steady_clock::now() > deadline_) {
        RCLCPP_INFO(node_->get_logger(), "centered service call timed out");
        // reset future so we can retry on next run
        future_ = rclcpp::Client<ros_interfaces::srv::Centered>::SharedFuture();
        return NodeStatus::RUNNING;
      }
      return NodeStatus::RUNNING;
    }

    // got response
    auto response = future_.get();
    future_ = rclcpp::Client<ros_interfaces::srv::Centered>::SharedFuture();
    float x = response->x;
    RCLCPP_INFO(node_->get_logger(), "centered service returned x=%.3f", x);

    if ((x >= -0.025f) && (x <= 0.025f)) {
      RCLCPP_INFO(node_->get_logger(), "No tennis ball detected, searching...");
      arduino_command_msg_.arduino_command = "STOP\n";
      arduino_command_publisher_->publish(arduino_command_msg_);
      return NodeStatus::SUCCESS;
    }
    //check if x is equal to infinity
    else if(std::isinf(x)){
        RCLCPP_INFO(node_->get_logger(), "No tennis ball detected, searching...");
        arduino_command_msg_.arduino_command = "STOP\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    else if(x < -.025f){
        RCLCPP_INFO(node_->get_logger(), "Ball is to the right, adjusting...");
        arduino_command_msg_.arduino_command = "RIGHT\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    else if(x > 0.025f){
        RCLCPP_INFO(node_->get_logger(), "Ball is to the left, adjusting...");
        arduino_command_msg_.arduino_command = "LEFT\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    return NodeStatus::RUNNING;
  }

  void onHalted() override
  {
    // clear pending future
    future_ = rclcpp::Client<ros_interfaces::srv::Centered>::SharedFuture();
  }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Client<ros_interfaces::srv::Centered>::SharedFuture future_;
    rclcpp::Client<ros_interfaces::srv::Centered>::SharedPtr client_;
    rclcpp::Publisher<message_interfaces::msg::ArduinoCommand>::SharedPtr arduino_command_publisher_;
    message_interfaces::msg::ArduinoCommand arduino_command_msg_;
    std::chrono::steady_clock::time_point deadline_;
};

class IsForwarded : public StatefulActionNode
{
public:
  IsForwarded(const std::string &name, const NodeConfiguration &config)
    : StatefulActionNode(name, config)
  {
    node_ = std::make_shared<rclcpp::Node>("is_forwarded_client");
    client_ = node_->create_client<ros_interfaces::srv::Forward>("forward");
    // create publisher here so it's always valid before onRunning() may publish
    arduino_command_publisher_ = node_->create_publisher<message_interfaces::msg::ArduinoCommand>("arduino_command", 10);
  }

  static PortsList providedPorts()
  {
    return {};
  }

  NodeStatus onStart() override
  {
    // if service not available yet, stay RUNNING
    if (!client_->wait_for_service(500ms)) {
      RCLCPP_INFO(node_->get_logger(), "centered service not available yet");
      return NodeStatus::RUNNING;
    }

    // send request and mark deadline
    auto request = std::make_shared<ros_interfaces::srv::Forward::Request>();
    future_ = client_->async_send_request(request);
    deadline_ = std::chrono::steady_clock::now() + 1s;
    return NodeStatus::RUNNING;
  }

  NodeStatus onRunning() override
  {
    rclcpp::spin_some(node_);

    if (!future_.valid()) {
      // send a request if none pending
      auto request = std::make_shared<ros_interfaces::srv::Forward::Request>();
      future_ = client_->async_send_request(request);
      deadline_ = std::chrono::steady_clock::now() + 1s;
      return NodeStatus::RUNNING;
    }

    // if response not ready yet
    if (future_.wait_for(std::chrono::milliseconds(0)) != std::future_status::ready) {
      if (std::chrono::steady_clock::now() > deadline_) {
        RCLCPP_INFO(node_->get_logger(), "forward service call timed out");
        // reset future so we can retry on next run
        future_ = rclcpp::Client<ros_interfaces::srv::Forward>::SharedFuture();
        return NodeStatus::RUNNING;
      }
      return NodeStatus::RUNNING;
    }

    // got response
    auto response = future_.get();
    future_ = rclcpp::Client<ros_interfaces::srv::Forward>::SharedFuture();
    float z = response->z;
    RCLCPP_INFO(node_->get_logger(), "forward service returned z=%.3f", z);

    if (z <= .3f) {
      arduino_command_msg_.arduino_command = "STOP\n";
      arduino_command_publisher_->publish(arduino_command_msg_);
      return NodeStatus::SUCCESS;
    }
    //check if x is equal to infinity
    else if(std::isinf(z)){
        RCLCPP_INFO(node_->get_logger(), "No tennis ball detected, searching...");
        arduino_command_msg_.arduino_command = "STOP\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    else{
        RCLCPP_INFO(node_->get_logger(), "Moving forward to tennis ball...");
        arduino_command_msg_.arduino_command = "FORWARD\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    return NodeStatus::RUNNING;
  }

  void onHalted() override
  {
    // clear pending future
    future_ = rclcpp::Client<ros_interfaces::srv::Forward>::SharedFuture();
  }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Client<ros_interfaces::srv::Forward>::SharedFuture future_;
    rclcpp::Client<ros_interfaces::srv::Forward>::SharedPtr client_;
    rclcpp::Publisher<message_interfaces::msg::ArduinoCommand>::SharedPtr arduino_command_publisher_;
    message_interfaces::msg::ArduinoCommand arduino_command_msg_;
    std::chrono::steady_clock::time_point deadline_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<IsCentered>("IsCentered");
  factory.registerNodeType<IsForwarded>("IsForwarded");

  // create the tree and tick until centered
  auto tree = factory.createTreeFromText(xml_text);
  std::cout << "Starting behavior tree to position ball for catapult..." << std::endl;
  NodeStatus status = NodeStatus::RUNNING;
  while (status != NodeStatus::SUCCESS) {
    status = tree.tickOnce();
    if (status == NodeStatus::SUCCESS) break;
    // small delay between attempts
    std::this_thread::sleep_for(100ms);
  }

  std::cout << "Ball is positioned for catapult, exiting behavior tree." << std::endl;
  rclcpp::shutdown();
}