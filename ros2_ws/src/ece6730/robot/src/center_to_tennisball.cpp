#include <memory>
#include <cmath>
#include <queue>
#include <mutex>
#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/tennis_ball_orientation.hpp"
#include "message_interfaces/msg/arduino_command.hpp"
#include "ros_interfaces/srv/centered.hpp"

class CenterToTennisBall : public rclcpp::Node
{
public:
  CenterToTennisBall()
  : Node("center_to_tennis_ball"), max_positions_(5)
  {
    // Initialize with invalid positions
    for (size_t i = 0; i < max_positions_; ++i) {
      x_positions_.push(std::numeric_limits<float>::infinity());
    }

    // Create service with proper callback binding
    x_service_ = create_service<ros_interfaces::srv::Centered>(
      "centered", 
      std::bind(&CenterToTennisBall::handle_centered_request, this, 
                std::placeholders::_1, std::placeholders::_2));

    // Create subscription with cleaner lambda
    tennisball_subscription_ = create_subscription<message_interfaces::msg::TennisBallOrientation>(
      "orientation_info", 10,
      [this](const message_interfaces::msg::TennisBallOrientation::SharedPtr msg) {
        this->process_tennis_ball_position(msg);
      });

    RCLCPP_INFO(this->get_logger(), "CenterToTennisBall node initialized");
  }

private:
  void process_tennis_ball_position(const message_interfaces::msg::TennisBallOrientation::SharedPtr msg)
  {
    std::lock_guard<std::mutex> lock(position_mutex_);
    
    // Add new position (remove oldest if queue is full)
    if (x_positions_.size() >= max_positions_) {
      x_positions_.pop();
    }
    x_positions_.push(msg->x);
    
    RCLCPP_DEBUG(this->get_logger(), "Received tennis ball position: x=%.2f, queue_size=%zu", 
                 msg->x, x_positions_.size());
  }

  void handle_centered_request(
    const std::shared_ptr<ros_interfaces::srv::Centered::Request> /* request */,
    std::shared_ptr<ros_interfaces::srv::Centered::Response> response)
  {
    std::lock_guard<std::mutex> lock(position_mutex_);
    
    if (x_positions_.empty()) {
      response->x = std::numeric_limits<float>::infinity();
      RCLCPP_WARN(this->get_logger(), "No tennis ball positions available");
    } else {
      // Get the most recent position
      response->x = x_positions_.back();
      RCLCPP_DEBUG(this->get_logger(), "Returning tennis ball x position: %.2f", response->x);
    }
  }

  // Member variables
  rclcpp::Subscription<message_interfaces::msg::TennisBallOrientation>::SharedPtr tennisball_subscription_;
  rclcpp::Service<ros_interfaces::srv::Centered>::SharedPtr x_service_;
  
  std::queue<float> x_positions_;
  std::mutex position_mutex_;
  const size_t max_positions_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CenterToTennisBall>());
  rclcpp::shutdown();
  return 0;
}