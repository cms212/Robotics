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
// This example is written for DYNAMIXEL X(excluding XL-320) and MX(2.0) series with U2D2.
// For other series, please refer to the product eManual and modify the Control Table addresses and other definitions.
// To test this example, please follow the commands below.
//
// Open terminal #1
// $ ros2 run dynamixel_sdk_examples read_write_node
//
// Open terminal #2 (run one of below commands at a time)
// $ ros2 topic pub -1 /set_position dynamixel_sdk_custom_interfaces/SetPosition "{id: 1, position: 1000}"
// $ ros2 service call /get_position dynamixel_sdk_custom_interfaces/srv/GetPosition "id: 1"
//
// Author: Will Son
*******************************************************************************/
#include <array>
#include <chrono>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include "dynamixel_sdk/dynamixel_sdk.h"
#include "dynamixel_sdk_custom_interfaces/msg/set_position.hpp"
#include "dynamixel_sdk_custom_interfaces/srv/get_position.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rcutils/cmdline_parser.h"
#include "message_interfaces/msg/arm_position.hpp"

// Control table address for X series (except XL-320)
#define ADDR_OPERATING_MODE 11
#define ADDR_TORQUE_ENABLE 64
#define ADDR_GOAL_POSITION 116
#define ADDR_PRESENT_POSITION 132

// Protocol version
#define PROTOCOL_VERSION 2.0  // Default Protocol version of DYNAMIXEL X series.

// Default setting
//#define BAUDRATE 57600  // Default Baudrate of DYNAMIXEL X series
#define BAUDRATE 1000000  // Default Baudrate of DYNAMIXEL X series
#define DEVICE_NAME "/dev/ttyUSB0"  // [Linux]: "/dev/ttyUSB*", [Windows]: "COM*"

using namespace std::chrono_literals;

dynamixel::PortHandler * portHandler;
dynamixel::PacketHandler * packetHandler;

uint8_t dxl_error = 0;
uint32_t goal_position = 0;
int dxl_comm_result = COMM_TX_FAIL;

class ArmPositionPublisher : public rclcpp::Node
{
public:
  ArmPositionPublisher()
  : Node("arm_position_publisher")
  {
    // Use optimized QoS for high-frequency publishing
    auto qos = rclcpp::QoS(rclcpp::KeepLast(10))
                 .reliability(rclcpp::ReliabilityPolicy::BestEffort)
                 .durability(rclcpp::DurabilityPolicy::Volatile);
    
    publisher_ = this->create_publisher<message_interfaces::msg::ArmPosition>("arm_position", qos);
    
    // Subscribe to goal position commands
    goal_position_subscriber_ = this->create_subscription<message_interfaces::msg::ArmPosition>(
      "arm_goal_position", qos,
      [this](message_interfaces::msg::ArmPosition::UniquePtr msg) -> void {
        this->handleGoalPositionCommand(std::move(msg));
      });
    
    // Pre-allocate message to avoid repeated allocations
    message_.arm_positions.reserve(1); // Only need space for 1 servo
    last_positions_.resize(1, 0); // Initialize with zeros for 1 servo
    
    auto arm_position_callback =
      [this]() -> void {
        // Clear previous data but keep allocated memory
        message_.arm_positions.clear();
        
        bool read_successful = true;
        uint32_t present_position = 0;
        
        // Read present position from servo ID 1 only
        dxl_comm_result = packetHandler->read4ByteTxRx(
          portHandler,
          1, // Only read from servo ID 1
          ADDR_PRESENT_POSITION,
          &present_position,
          &dxl_error
        );

        if (dxl_comm_result != COMM_SUCCESS) {
          RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
            "Failed to read from ID 1: %s", packetHandler->getTxRxResult(dxl_comm_result));
          read_successful = false;
          present_position = last_positions_[0]; // Use last known position
        } else if (dxl_error != 0) {
          RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
            "Dynamixel error on ID 1: %s", packetHandler->getRxPacketError(dxl_error));
          read_successful = false;
          present_position = last_positions_[0]; // Use last known position
        } else {
          // Only log successful reads occasionally to reduce I/O overhead
          if (++read_count_ % 200 == 0) {
            RCLCPP_DEBUG(this->get_logger(), "Read [ID: 1] [Position: %d]", present_position);
          }
          last_positions_[0] = present_position; // Store successful read
        }

        message_.arm_positions.push_back(present_position);
        
        // Only publish if we have valid data
        if (read_successful || read_count_ > 1) {
          this->publisher_->publish(message_);
        }
        
        // Periodic status log (much less frequent)
        if (read_count_ % 500 == 0) {
          RCLCPP_INFO(this->get_logger(), "Published %d position readings", read_count_);
        }
      };
    timer_ = this->create_wall_timer(5ms, arm_position_callback); // Much faster timer: 100Hz
  }

private:
  void handleGoalPositionCommand(message_interfaces::msg::ArmPosition::UniquePtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Received goal position command with %zu positions", msg->arm_positions.size());
    
    // Only write goal position to servo ID 1 (first servo)
    if (!msg->arm_positions.empty()) {
      uint32_t goal_pos = msg->arm_positions[0];  // Use first position for servo ID 1
      
      dxl_comm_result = packetHandler->write4ByteTxRx(
        portHandler,
        1,  // Only servo ID 1
        ADDR_GOAL_POSITION,
        goal_pos,
        &dxl_error
      );
      
      if (dxl_comm_result != COMM_SUCCESS) {
        RCLCPP_WARN(this->get_logger(), "Failed to write goal position to ID 1: %s", 
                   packetHandler->getTxRxResult(dxl_comm_result));
      } else if (dxl_error != 0) {
        RCLCPP_WARN(this->get_logger(), "Dynamixel error writing to ID 1: %s", 
                   packetHandler->getRxPacketError(dxl_error));
      } else {
        RCLCPP_DEBUG(this->get_logger(), "Set goal position for ID 1: %u", goal_pos);
      }
    } else {
      RCLCPP_WARN(this->get_logger(), "Received empty goal position command");
    }
  }

private:
  uint8_t numIDs_ = 1;  // Number of Dynamixel servos (only servo ID 1)
  
  rclcpp::Publisher<message_interfaces::msg::ArmPosition>::SharedPtr publisher_;
  rclcpp::Subscription<message_interfaces::msg::ArmPosition>::SharedPtr goal_position_subscriber_;
  rclcpp::TimerBase::SharedPtr timer_;
  
  // Optimization variables
  message_interfaces::msg::ArmPosition message_; // Pre-allocated message
  std::vector<uint32_t> last_positions_; // Store last known positions
  uint32_t read_count_ = 0; // Counter for throttled logging
};

void setupDynamixel(uint8_t dxl_id)
{
  // Use Position Control Mode
  dxl_comm_result = packetHandler->write1ByteTxRx(
    portHandler,
    dxl_id,
    ADDR_OPERATING_MODE,
    3,
    &dxl_error
  );

  if (dxl_comm_result != COMM_SUCCESS) {
    RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to set Position Control Mode.");
  } else {
    RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to set Position Control Mode.");
  }

  // Enable Torque of DYNAMIXEL
  dxl_comm_result = packetHandler->write1ByteTxRx(
    portHandler,
    dxl_id,
    ADDR_TORQUE_ENABLE,
    1,
    &dxl_error
  );

  if (dxl_comm_result != COMM_SUCCESS) {
    RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to enable torque.");
  } else {
    RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to enable torque.");
  }
}

int main(int argc, char * argv[])
{
  portHandler = dynamixel::PortHandler::getPortHandler(DEVICE_NAME);
  packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

  // Open Serial Port
  dxl_comm_result = portHandler->openPort();
  if (dxl_comm_result == false) {
    RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to open the port!");
    return -1;
  } else {
    RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to open the port.");
  }

  // Set the baudrate of the serial port (use DYNAMIXEL Baudrate)
  dxl_comm_result = portHandler->setBaudRate(BAUDRATE);
  if (dxl_comm_result == false) {
    RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to set the baudrate!");
    return -1;
  } else {
    RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to set the baudrate.");
  }

  setupDynamixel(BROADCAST_ID);

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ArmPositionPublisher>());
  rclcpp::shutdown();

  // Disable Torque of DYNAMIXEL
  packetHandler->write1ByteTxRx(
    portHandler,
    BROADCAST_ID,
    ADDR_TORQUE_ENABLE,
    0,
    &dxl_error
  );

  return 0;
}