// Copyright 2021 ROBOTIS CO., LTD.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*******************************************************************************
// This node subscribes to arm position messages and calculates new goal positions
// based on the current position. It publishes goal position commands instead of
// directly accessing the Dynamixel hardware.
//
// Author: Modified from Will Son's original code
*******************************************************************************/
#include <chrono>
#include <cstdio>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/arm_position.hpp"

using namespace std::chrono_literals;



class ArmPositionSubscriber : public rclcpp::Node
{
public:
  ArmPositionSubscriber()
  : Node("arm_position_subscriber"), clockwise_(false)
  {
    // Use QoS settings optimized for high-frequency data
    auto qos = rclcpp::QoS(rclcpp::KeepLast(10))
                 .reliability(rclcpp::ReliabilityPolicy::BestEffort)
                 .durability(rclcpp::DurabilityPolicy::Volatile);

    // Subscribe to current arm positions
    position_subscriber_ = this->create_subscription<message_interfaces::msg::ArmPosition>(
      "arm_position", qos,
      [this](message_interfaces::msg::ArmPosition::UniquePtr msg) -> void {
        this->handleArmPositionUpdate(std::move(msg));
      });

    // Publisher for goal position commands
    goal_publisher_ = this->create_publisher<message_interfaces::msg::ArmPosition>(
      "arm_goal_position", qos);

    RCLCPP_INFO(this->get_logger(), "Arm Position Subscriber initialized");
  }

private:
  void handleArmPositionUpdate(message_interfaces::msg::ArmPosition::UniquePtr msg)
  {
    if (msg->arm_positions.empty()) {
      RCLCPP_WARN(this->get_logger(), "Received empty arm positions message");
      return;
    }

    // Check first servo position to determine direction
    uint32_t first_position = msg->arm_positions[0];
    
    if (first_position <= 1024) {
      clockwise_ = false;
    } else if (first_position >= 3072) {
      clockwise_ = true;
    }

    // Create goal position message
    auto goal_msg = std::make_unique<message_interfaces::msg::ArmPosition>();
    goal_msg->arm_positions.reserve(msg->arm_positions.size());

    // Calculate new goal positions based on current positions
    for (size_t i = 0; i < msg->arm_positions.size(); i++) {
      uint32_t current_pos = msg->arm_positions[i];
      uint32_t goal_pos;

      if (clockwise_) {
        goal_pos = (current_pos >= 100) ? current_pos - 100 : 0;
      } else {
        goal_pos = (current_pos <= 4095 - 100) ? current_pos + 100 : 4095;
      }

      goal_msg->arm_positions.push_back(goal_pos);
    }

    // Publish goal positions
    goal_publisher_->publish(std::move(goal_msg));
    
    RCLCPP_DEBUG(this->get_logger(), 
      "Published goal positions. Direction: %s, First goal: %u", 
      clockwise_ ? "clockwise" : "counter-clockwise", 
      goal_msg->arm_positions[0]);
  }

private:
  rclcpp::Subscription<message_interfaces::msg::ArmPosition>::SharedPtr position_subscriber_;
  rclcpp::Publisher<message_interfaces::msg::ArmPosition>::SharedPtr goal_publisher_;
  bool clockwise_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ArmPositionSubscriber>());
  rclcpp::shutdown();
  return 0;
}