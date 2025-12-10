// Minimal behavior tree that queries the `centered` service repeatedly
// and finishes the single stage when the service returns X within [-0.25, 0.25] range.

#include <chrono>
#include <thread>
#include <memory>
#include <iostream>
#include <cmath>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "ros_interfaces/srv/centered.hpp"
#include "ros_interfaces/srv/arm_service.hpp"
#include "ros_interfaces/srv/arm_position.hpp"
#include "ros_interfaces/srv/forward.hpp"
#include "message_interfaces/msg/arduino_command.hpp"
#include "behaviortree_cpp/bt_factory.h"


using namespace std::chrono_literals;

using namespace BT;



/*static const char* xml_text = R"(
<root BTCPP_format="4">
  <BehaviorTree ID="MainTree">
    <Sequence name="root_sequence">
      <PickUpTennisBall name="PickUpTennisBall"/>
    </Sequence>
  </BehaviorTree>
</root>
 )";*/


static const char* xml_text = R"(
<root BTCPP_format="4">
  <BehaviorTree ID="MainTree">
    <Sequence name="root_sequence">
      <Search name="Search"/>
      <IsCentered name="IsCentered"/>
      <IsForwarded name="IsForwarded"/>
      <PickUpTennisBall name="PickUpTennisBall"/>
    </Sequence>
  </BehaviorTree>
</root>
 )";


class Search : public StatefulActionNode
{
public:
  Search(const std::string &name, const NodeConfiguration &config)
    : StatefulActionNode(name, config)
  {
    node_ = std::make_shared<rclcpp::Node>("search_client");
    client_ = node_->create_client<ros_interfaces::srv::Centered>("centered");
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

    if (x <= 1.0f) {
      RCLCPP_INFO(node_->get_logger(), "Tennis Ball FOUND!");
      arduino_command_msg_.arduino_command = "STOP\n";
      arduino_command_publisher_->publish(arduino_command_msg_);
      return NodeStatus::SUCCESS;
    }
    //check if x is equal to infinity
    else if(std::isinf(x)){
        arduino_command_msg_.arduino_command = "LEFT FAST\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    else if(x > 1.0f){
        arduino_command_msg_.arduino_command = "LEFT FAST\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    return NodeStatus::RUNNING;
  }

  void onHalted() override
  {
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

class IsCentered : public StatefulActionNode
{
public:
  IsCentered(const std::string &name, const NodeConfiguration &config)
    : StatefulActionNode(name, config)
  {
    node_ = std::make_shared<rclcpp::Node>("is_centered_client");
    client_ = node_->create_client<ros_interfaces::srv::Centered>("centered");
    arduino_command_publisher_ = node_->create_publisher<message_interfaces::msg::ArduinoCommand>("arduino_command", 10);
  }

  static PortsList providedPorts()
  {
    return {};
  }

  NodeStatus onStart() override
  {
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

    if ((x > -0.015f) && (x < 0.015f)) {
      arduino_command_msg_.arduino_command = "STOP\n";
      arduino_command_publisher_->publish(arduino_command_msg_);
      return NodeStatus::SUCCESS;
    }
    //check if x is equal to infinity
    else if(std::isinf(x)){
        arduino_command_msg_.arduino_command = "STOP\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    else if(x < -0.015f){
        arduino_command_msg_.arduino_command = "RIGHT\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    else if(x > 0.015f){
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
    RCLCPP_INFO(node_->get_logger(), "z value: %3.4f", z);
    if (z <= 0.13f) {
      arduino_command_msg_.arduino_command = "STOP\n";
      arduino_command_publisher_->publish(arduino_command_msg_);
      return NodeStatus::SUCCESS;
    }
    //check if x is equal to infinity
    else if(std::isinf(z)){
        arduino_command_msg_.arduino_command = "STOP\n";
        arduino_command_publisher_->publish(arduino_command_msg_);
    }
    else{
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


class PickUpTennisBall : public StatefulActionNode
{
  public:
    PickUpTennisBall(const std::string &name, const NodeConfiguration &config)
      : StatefulActionNode(name, config)
    {
      node_ = std::make_shared<rclcpp::Node>("PickUpTennisBall_client");
      arm_service_client_ = node_->create_client<ros_interfaces::srv::ArmService>("arm_service");
      arm_position_client_ = node_->create_client<ros_interfaces::srv::ArmPosition>("arm_position_service");
    }

    static PortsList providedPorts()
    {
      return {};
    }

    NodeStatus onStart() override
    {
      if (!arm_service_client_->wait_for_service(500ms) || !arm_position_client_->wait_for_service(500ms)) {
        RCLCPP_INFO(node_->get_logger(), "arm services not available yet");
        return NodeStatus::RUNNING;
      }

      // initialize index and ensure we have joints to process
      current_index_ = 0;
      if (joints_.empty()) {
        RCLCPP_INFO(node_->get_logger(), "No configured joints to move in PickUpTennisBall");
        return NodeStatus::SUCCESS;
      }

      // send initial set request for the first joint
      if (!set_sent_) {
        int joint = joints_.at(current_index_).first;
        int pos = joints_.at(current_index_).second;
        auto request = std::make_shared<ros_interfaces::srv::ArmService::Request>();
        request->joint = joint;
        request->joint_pos = pos;
        set_future_ = arm_service_client_->async_send_request(request);
        set_deadline_ = std::chrono::steady_clock::now() + 1s;
        set_sent_ = true;
      }

      return NodeStatus::RUNNING;
    }

    NodeStatus onRunning() override
    {
      rclcpp::spin_some(node_);
      // check set request
      if (set_sent_ && set_future_.valid()) {
        if (set_future_.wait_for(std::chrono::milliseconds(0)) != std::future_status::ready) {
          if (std::chrono::steady_clock::now() > set_deadline_) {
            RCLCPP_INFO(node_->get_logger(), "arm set request timed out");
            set_future_ = rclcpp::Client<ros_interfaces::srv::ArmService>::SharedFuture();
            set_sent_ = false; // allow retry
          }
          // still waiting for set to complete
        } else {
          auto result = set_future_.get();
          set_future_ = rclcpp::Client<ros_interfaces::srv::ArmService>::SharedFuture();
          if (result) {
            RCLCPP_INFO(node_->get_logger(), "arm set request returned result=%d", result->result);
          }
          // proceed to poll position regardless of set result
        }
      }

      // request position for the current joint if none pending
      if (!pos_future_.valid()) {
        int joint = joints_.at(current_index_).first;
        auto req = std::make_shared<ros_interfaces::srv::ArmPosition::Request>();
        req->joint = joint;
        pos_future_ = arm_position_client_->async_send_request(req);
        pos_deadline_ = std::chrono::steady_clock::now() + 1s;
        return NodeStatus::RUNNING;
      }

      if (pos_future_.wait_for(std::chrono::milliseconds(0)) != std::future_status::ready) {
        if (std::chrono::steady_clock::now() > pos_deadline_) {
          RCLCPP_INFO(node_->get_logger(), "arm position request timed out");
          pos_future_ = rclcpp::Client<ros_interfaces::srv::ArmPosition>::SharedFuture();
        }
        return NodeStatus::RUNNING;
      }

      auto pres = pos_future_.get();
      pos_future_ = rclcpp::Client<ros_interfaces::srv::ArmPosition>::SharedFuture();
      int current = pres->position;
      int joint = joints_.at(current_index_).first;
      int target = joints_.at(current_index_).second;
      RCLCPP_INFO(node_->get_logger(), "current joint position=%d", current);
      RCLCPP_INFO(node_->get_logger(), "PICKING UP TENNIS BALL - JOINT ID: %d", joint);

      int threshold = (joint == 5) ? 45 : 70;
      if (std::abs(current - target) <= threshold) {
        // move to next joint
        if (current_index_ + 1 >= joints_.size()) {
          RCLCPP_INFO(node_->get_logger(), "All joints reached target positions");
          return NodeStatus::SUCCESS;
        }
        RCLCPP_INFO(node_->get_logger(), "Joint reached target %d", target);
        current_index_++;
        int next_joint = joints_.at(current_index_).first;
        int next_pos = joints_.at(current_index_).second;
        RCLCPP_INFO(node_->get_logger(), "Moving to next joint %d", next_joint);
        // prepare and immediately send set command for the next joint
        set_sent_ = false; // allow sending
        if (!set_sent_) {
          auto request = std::make_shared<ros_interfaces::srv::ArmService::Request>();
          request->joint = next_joint;
          request->joint_pos = next_pos;
          set_future_ = arm_service_client_->async_send_request(request);
          set_deadline_ = std::chrono::steady_clock::now() + 1s;
          set_sent_ = true;
        }
        return NodeStatus::RUNNING;
      }

      return NodeStatus::RUNNING;
    }

    void onHalted() override
    {
      // Nothing to clean up
    }
  private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Client<ros_interfaces::srv::ArmService>::SharedPtr arm_service_client_;
    rclcpp::Client<ros_interfaces::srv::ArmPosition>::SharedPtr arm_position_client_;
    rclcpp::Client<ros_interfaces::srv::ArmService>::SharedFuture set_future_;
    rclcpp::Client<ros_interfaces::srv::ArmPosition>::SharedFuture pos_future_;
    std::chrono::steady_clock::time_point set_deadline_;
    std::chrono::steady_clock::time_point pos_deadline_;
    bool set_sent_ = false;
    size_t current_index_ = 0;
    //std::vector<std::pair<int,int>> joints_ = {{5,3150},{4,2500}, {3,1500}, {2,2100}, {1,2050}, {2, 2000}, {3, 2150}, {4, 3075}, {2,1500}, {5,1500}};
    std::vector<std::pair<int,int>> joints_ = {{5,3150},{4,2500}, {3,1500}, {2,2000}, {1,2100}, {3, 3100}, {4, 1000}, {2, 1090}, {5, 2250},
                                              {2,2100}, {1,0}, {3,2500}, {4, 1600}, {5,2800}};

};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<Search>("Search");
  factory.registerNodeType<IsCentered>("IsCentered");
  factory.registerNodeType<IsForwarded>("IsForwarded");
  factory.registerNodeType<PickUpTennisBall>("PickUpTennisBall");

  // debug: print the XML text being parsed so we can confirm node names
  std::cout << "--- Behavior Tree XML ---\n" << xml_text << "\n--- end XML ---\n";
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
