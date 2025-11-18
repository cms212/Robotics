#include <memory>
#include <math.h>
#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/tennis_ball_orientation.hpp"
#include "message_interfaces/msg/arduino_command.hpp"
#include <vector>
#include "ros_interfaces/srv/centered.hpp"

class CenterToTennisBall : public rclcpp::Node
{
public:
  CenterToTennisBall()
  : Node("center_to_tennis_ball")
  {
    arduino_command_publisher_ =
      this->create_publisher<message_interfaces::msg::ArduinoCommand>("arduino_command", 10);
    auto ball_position =
      [this](message_interfaces::msg::TennisBallOrientation::UniquePtr msg) -> void {
        //RCLCPP_INFO(this->get_logger(), "X Position: %f", msg->x);
        //RCLCPP_INFO(this->get_logger(), "Y Position: %f", msg->y);
        //RCLCPP_INFO(this->get_logger(), "Z Position: %f", msg->z);
        x_positions.insert(x_positions.begin(), msg->x);      
        if (x_positions.size() > 5) {
          x_positions.pop_back();             
        }
  };
    x_service = create_service<ros_interfaces::srv::Centered>("centered", CenterToTennisBall::ball_x);
    tennisball_to_camera_subscription_ =
      this->create_subscription<message_interfaces::msg::TennisBallOrientation>("orientation_info", 10, ball_position);
  }

  void ball_x(ros_interfaces::srv::Centered::Request> request,
          std::shared_ptr<ros_interfaces::srv::Centered::Response> response){
          float x = x_positions.front();
          x_positions.erase(x_positions.begin());
          x_positions.push_back(INFINITY);
          response->X = x;
  }


private:
  rclcpp::Subscription<message_interfaces::msg::TennisBallOrientation>::SharedPtr tennisball_to_camera_subscription_;
  std::vector<float> x_positions(5, INFINITY);
  rclcpp::Service<ros_interfaces::srv::Centered>::SharedPtr x_service;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CenterToTennisBall>());
  rclcpp::shutdown();
  return 0;
}