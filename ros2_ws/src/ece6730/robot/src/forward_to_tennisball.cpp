#include <memory>
#include <cmath>
#include <deque>
#include <mutex>
#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/tennis_ball_orientation.hpp"
#include "message_interfaces/msg/arduino_command.hpp"
#include "ros_interfaces/srv/forward.hpp"

class ForwardToTennisBall : public rclcpp::Node
{
public:
  ForwardToTennisBall()
  : Node("forward_to_tennis_ball"), max_positions_(5)
  {
    // Initialize with invalid positions
    for (size_t i = 0; i < max_positions_; ++i) {
      z_positions_.push_back(std::numeric_limits<float>::infinity());
    }

    // Create service with proper callback binding
    z_service_ = create_service<ros_interfaces::srv::Forward>(
      "forward", 
      std::bind(&ForwardToTennisBall::handle_forward_request, this, 
                std::placeholders::_1, std::placeholders::_2));

    tennisball_subscription_ = create_subscription<message_interfaces::msg::TennisBallOrientation>(
      "orientation_info", 10,
      [this](const message_interfaces::msg::TennisBallOrientation::SharedPtr msg) {
        this->process_tennis_ball_position(msg);
      });

    RCLCPP_INFO(this->get_logger(), "ForwardToTennisBall node initialized");
  }

private:
  void process_tennis_ball_position(const message_interfaces::msg::TennisBallOrientation::SharedPtr msg)
  {
    std::lock_guard<std::mutex> lock(position_mutex_);
    
    if (z_positions_.size() >= max_positions_) {
      z_positions_.pop_front();
    }
    z_positions_.push_back(msg->z);
    
    //RCLCPP_INFO(this->get_logger(), "Received tennis ball position: x=%.2f, queue_size=%zu", 
                 //msg->x, x_positions_.size());
  }

  void handle_forward_request(
    const std::shared_ptr<ros_interfaces::srv::Forward::Request> /* request */,
    std::shared_ptr<ros_interfaces::srv::Forward::Response> response)
  {
    std::lock_guard<std::mutex> lock(position_mutex_);
    
    if (z_positions_.empty()) {
      response->z = std::numeric_limits<float>::infinity();
      //RCLCPP_INFO(this->get_logger(), "No tennis ball positions available");
    } else {
      // Get the most recent position, remove it, and mark it consumed by pushing infinity
      response->z = z_positions_.back();
      z_positions_.pop_back();
      z_positions_.push_back(std::numeric_limits<float>::infinity());
      //RCLCPP_INFO(this->get_logger(), "Returning tennis ball x position: %.2f", response->x);
    }
  }

  // Member variables
  rclcpp::Subscription<message_interfaces::msg::TennisBallOrientation>::SharedPtr tennisball_subscription_;
  rclcpp::Service<ros_interfaces::srv::Forward>::SharedPtr z_service_;
  
  std::deque<float> z_positions_;
  std::mutex position_mutex_;
  const size_t max_positions_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ForwardToTennisBall>());
  rclcpp::shutdown();
  return 0;
}