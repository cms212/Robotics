
#include "dynamixel_sdk/dynamixel_sdk.h"
#include "rclcpp/rclcpp.hpp"
#include "ros_interfaces/srv/arm_service.hpp"
#include "ros_interfaces/srv/arm_position.hpp"
#include <mutex>

#define ADDR_OPERATING_MODE 11
#define ADDR_TORQUE_ENABLE 64
#define ADDR_GOAL_POSITION 116
#define ADDR_PRESENT_POSITION 132
#define ADDR_PROFILE_VELOCITY  112
// Common addresses for Protocol 2.0 control table
#define ADDR_MODEL_NUMBER 0
#define ADDR_PROFILE_ACCELERATION 108

#define BAUDRATE 1000000  
#define DEVICE_NAME "/dev/ttyUSB0" 

#define PROTOCOL_VERSION 2.0

dynamixel::PortHandler * portHandler;
dynamixel::PacketHandler * packetHandler;

uint8_t dxl_error = 0;
uint32_t goal_position = 0;
int dxl_comm_result = COMM_TX_FAIL;

class ArmService : public rclcpp::Node
{
public:
  ArmService()
  : Node("arm_service")
  {

    arm_service_ = create_service<ros_interfaces::srv::ArmService>(
      "arm_service", 
      std::bind(&ArmService::handle_arm_request, this, 
                std::placeholders::_1, std::placeholders::_2));
    arm_position_service_ = create_service<ros_interfaces::srv::ArmPosition>(
      "arm_position_service", 
      std::bind(&ArmService::handle_arm_position_request, this, 
                std::placeholders::_1, std::placeholders::_2));

  }

private:
  void handle_arm_request(const std::shared_ptr<ros_interfaces::srv::ArmService::Request> request,
                          std::shared_ptr<ros_interfaces::srv::ArmService::Response> response)
  {
    std::lock_guard<std::mutex> lock(dynamixel_mutex_);
    if (!packetHandler || !portHandler) {
      RCLCPP_ERROR(this->get_logger(), "Dynamixel handlers not initialized");
      response->result = -1;
      return;
    }

    response->result = packetHandler->write4ByteTxRx(
        portHandler,
        request->joint,  // servo id
        ADDR_GOAL_POSITION,
        request->joint_pos,
        &dxl_error
      );
    if (response->result != COMM_SUCCESS) {
      RCLCPP_ERROR(this->get_logger(), "Failed to write goal position, comm result=%d, dxl_error=%u", response->result, dxl_error);
    }
  }

  void handle_arm_position_request(const std::shared_ptr<ros_interfaces::srv::ArmPosition::Request> request,
                          std::shared_ptr<ros_interfaces::srv::ArmPosition::Response> response)
  {
    uint32_t position = 0;
    std::lock_guard<std::mutex> lock(dynamixel_mutex_);
    if (!packetHandler || !portHandler) {
      RCLCPP_ERROR(this->get_logger(), "Dynamixel handlers not initialized");
      response->result = -1;
      response->position = -1;
      return;
    }

    response->result = packetHandler->read4ByteTxRx(
        portHandler,
        request->joint,
        ADDR_PRESENT_POSITION,
        &position,
        &dxl_error
      );

    if (response->result != COMM_SUCCESS) {
        RCLCPP_ERROR(this->get_logger(), "Dynamixel comm failure: %d", response->result);
        response->position =  -1;
    } 
    else if (dxl_error != 0) {
        RCLCPP_ERROR(this->get_logger(), "Dynamixel reported error: %u", dxl_error);
        response->position =  -2;    
    }
    else{
        response->position = static_cast<int32_t>(position);
    }
}

  rclcpp::Service<ros_interfaces::srv::ArmService>::SharedPtr arm_service_;
  rclcpp::Service<ros_interfaces::srv::ArmPosition>::SharedPtr arm_position_service_;
  std::mutex dynamixel_mutex_;

}
;

void setupDynamixel(uint8_t dxl_id)
{

  
  // Set Operating Mode to Position Control Mode
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
  
  uint16_t model;
packetHandler->read2ByteTxRx(portHandler, 2, 0, &model);
RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Model Number: %d", model);

dxl_comm_result = packetHandler->write1ByteTxRx(
    portHandler,
    1,
    10,     // ADDR_DRIVE_MODE
    0,      // Disable time-based profile
    &dxl_error
);

if (dxl_comm_result != COMM_SUCCESS) {
    RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to Disable Time-Based Profile.");
  } else {
    RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to Disable Time-Based Profile.");
  }

  dxl_comm_result = packetHandler->write4ByteTxRx(
    portHandler,
    1,
    ADDR_PROFILE_ACCELERATION,
    500,       
    &dxl_error
);
  for (int i = 0; i <= 4; i++) {
    dxl_comm_result = packetHandler->write4ByteTxRx(
      portHandler,
      i,
      112,       
      1500,        
      &dxl_error
    );
    if (dxl_comm_result != COMM_SUCCESS) {
      RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to set Velocity Control Mode.");
    } else {
      RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to set Velocity Control Mode.");
    }
    }
}

int main(int argc, char * argv[])
{

    portHandler = dynamixel::PortHandler::getPortHandler(DEVICE_NAME);
     packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

  // Open Serial Port
    bool opened = portHandler->openPort();
    if (!opened) {
      RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to open the port!");
      return -1;
    } else {
      RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to open the port.");
    }

  // Set the baudrate of the serial port (use DYNAMIXEL Baudrate)
    bool baud_ok = portHandler->setBaudRate(BAUDRATE);
    if (!baud_ok) {
      RCLCPP_ERROR(rclcpp::get_logger("arm_position_publisher"), "Failed to set the baudrate!");
      return -1;
      } else {
      RCLCPP_INFO(rclcpp::get_logger("arm_position_publisher"), "Succeeded to set the baudrate.");
    }

    setupDynamixel(BROADCAST_ID);

    rclcpp::init(argc, argv);
    auto node = std::make_shared<ArmService>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    // Disable Torque of DYNAMIXEL
    if (packetHandler && portHandler) {
      packetHandler->write1ByteTxRx(
          portHandler,
          BROADCAST_ID,
          ADDR_TORQUE_ENABLE,
          0,
          &dxl_error
      );
    }
    if (portHandler && portHandler->is_using_) {
      portHandler->closePort();
    }
    return 0;
}