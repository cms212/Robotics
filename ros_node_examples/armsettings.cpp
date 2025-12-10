#include "dynamixel_sdk/dynamixel_sdk.h"

#define BAUDRATE 1000000  
#define DEVICE_NAME "/dev/ttyUSB0" 

#define PROTOCOL_VERSION 2.0

dynamixel::PortHandler * portHandler;
dynamixel::PacketHandler * packetHandler;

int dxl_comm_result = COMM_TX_FAIL;


int main (int argc, char * argv[])
{

    portHandler = dynamixel::PortHandler::getPortHandler(DEVICE_NAME);
    packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

    bool opened = portHandler->openPort();
    if (!opened) {
      RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to open the port!");
      return -1;
    } else {
      RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to open the port.");
    }

    bool baud_ok = portHandler->setBaudRate(BAUDRATE);
    if (!baud_ok) {
      RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to set the baudrate!");
      return -1;
      } else {
      RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to set the baudrate.");
    }


    if (portHandler && portHandler->is_using_) {
      portHandler->closePort();
    }
    return 0;
}