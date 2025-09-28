#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("camera_subscriber")
  {
    auto Image_callback =
      [this](sensor_msgs::msg::Image::UniquePtr msg) -> void {
        RCLCPP_INFO(this->get_logger(), "Time Stamp: 'Seconds: %d'", msg->header.stamp.sec);
        RCLCPP_INFO(this->get_logger(), "Time Stamp: 'Nano Seconds: %d'", msg->header.stamp.nanosec);
      };
    subscription_ =
      this->create_subscription<sensor_msgs::msg::Image>("image_raw", 10, Image_callback);
  }

private:
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}