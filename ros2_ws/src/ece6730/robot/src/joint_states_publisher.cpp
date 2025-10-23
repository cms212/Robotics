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
#include <chrono>
#include <cstdio>
#include <memory>
#include <string>

#include "dynamixel_sdk/dynamixel_sdk.h"
#include "dynamixel_sdk_custom_interfaces/msg/set_position.hpp"
#include "dynamixel_sdk_custom_interfaces/srv/get_position.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rcutils/cmdline_parser.h"
#include <sensor_msgs/msg/joint_state.hpp>

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

class JointStatesPublisher : public rclcpp::Node
{
public:
  JointStatesPublisher()
  : Node("joint_states_publisher")
  {
    publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    auto joint_state_callback =
      [this]() -> void {
        auto joint_states = sensor_msgs::msg::JointState();
        joint_states.header.stamp=this->get_clock()->now();
        joint_states.name = {"joint1", "joint2", "joint3", "joint4", "joint5"};
        for (uint8_t id = 0; id < numIDs_; id++) {
          uint32_t present_position = 0;
          // Read present position
          dxl_comm_result = packetHandler->read4ByteTxRx(
            portHandler,
            id + 1,
            ADDR_PRESENT_POSITION,
            &present_position,
            &dxl_error
          );

          if (dxl_comm_result != COMM_SUCCESS) {
            RCLCPP_ERROR(this->get_logger(), "%s", packetHandler->getTxRxResult(dxl_comm_result));
          } else if (dxl_error != 0) {
            RCLCPP_ERROR(this->get_logger(), "%s", packetHandler->getRxPacketError(dxl_error));
          }

          joint_states.position.push_back(present_position  * (2 * M_PI / 4095));  // Convert to radians
        
        /*RCLCPP_INFO(
            this->get_logger(),
            "Joint: %s\n Position: %d%s",
            joint_states.name[id].c_str(),
            present_position,
            "\n\n-----------------------------"
          );*/
        }
        this->publisher_->publish(joint_states);
      };
    timer_ = this->create_wall_timer(33ms, joint_state_callback);
  }


private:
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  uint8_t numIDs_ = 5;
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
    0,
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
  rclcpp::spin(std::make_shared<JointStatesPublisher>());
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