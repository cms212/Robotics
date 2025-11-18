#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/tennis_ball_orientation.hpp"
#include "message_interfaces/msg/arduino_command.hpp"

class MovementToTennisBall : public rclcpp::Node
{
public:
  MovementToTennisBall()
  : Node("movement_to_tennis_ball")
  {
    arduino_command_publisher_ =
      this->create_publisher<message_interfaces::msg::ArduinoCommand>("arduino_command", 10);
    auto movement_command =
      [this](message_interfaces::msg::TennisBallOrientation::UniquePtr msg) -> void {
        //RCLCPP_INFO(this->get_logger(), "X Position: %f", msg->x);
        //RCLCPP_INFO(this->get_logger(), "Y Position: %f", msg->y);
        //RCLCPP_INFO(this->get_logger(), "Z Position: %f", msg->z);
        if(turn){
          if (msg->x < -0.05 && !turning){
              arduino_command_msg_.arduino_command = "RIGHT\n";
              RCLCPP_INFO(this->get_logger(), "RIGHT");
              turning = true;
              arduino_command_publisher_->publish(arduino_command_msg_);
          }
          else if (msg->x > 0.05 && !turning){
              arduino_command_msg_.arduino_command = "LEFT\n";
              RCLCPP_INFO(this->get_logger(), "LEFT");
              turning = true;
              arduino_command_publisher_->publish(arduino_command_msg_);
          }
          else if (msg->x >= -0.05 && msg->x <= 0.05 && turning){
              turning = false;
              turn = false;
              forward = true;
              RCLCPP_INFO(this->get_logger(), "CENTERED");
          }
          return;
        }
        else if(forward){
          
          if (msg->z >= .5 && !moving){
            arduino_command_msg_.arduino_command = "FORWARD\n";
            RCLCPP_INFO(this->get_logger(), "FORWARD");
            moving = true;
            arduino_command_publisher_->publish(arduino_command_msg_);
        }
        
        else if (msg->z < .5 && moving){
            arduino_command_msg_.arduino_command = "STOP\n";
            RCLCPP_INFO(this->get_logger(), "STOP");
            forward = false;
            moving = false;
            arduino_command_publisher_->publish(arduino_command_msg_);
        }
        else if (msg->z < .5 && !moving){
            forward = false;
            RCLCPP_INFO(this->get_logger(), "CLOSE ENOUGH");
            arduino_command_msg_.arduino_command = "STOP\n";
            RCLCPP_INFO(this->get_logger(), "STOP");
            arduino_command_publisher_->publish(arduino_command_msg_);
        }
      }
      else{
        if (msg->x < -0.05 || msg->x > 0.05){
            turn = true;
            RCLCPP_INFO(this->get_logger(), "NEED TO TURN");
        }
        else if (msg->z >= .5){
            forward = true;
            RCLCPP_INFO(this->get_logger(), "NEED TO MOVE FORWARD");
      }
    }
  };
    tennisball_to_camera_subscription_ =
      this->create_subscription<message_interfaces::msg::TennisBallOrientation>("orientation_info", 10, movement_command);
}

private:
  rclcpp::Subscription<message_interfaces::msg::TennisBallOrientation>::SharedPtr tennisball_to_camera_subscription_;
  rclcpp::Publisher<message_interfaces::msg::ArduinoCommand>::SharedPtr arduino_command_publisher_;
  message_interfaces::msg::ArduinoCommand arduino_command_msg_;
  bool forward = false;
  bool moving = false;
  bool turn = true;
  bool turning = false;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MovementToTennisBall>());
  rclcpp::shutdown();
  return 0;
}