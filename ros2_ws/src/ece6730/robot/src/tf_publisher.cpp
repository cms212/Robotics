#include <functional>
#include <memory>
#include <sstream>
#include <string>

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "message_interfaces/msg/tennis_ball_orientation.hpp"


class CameraToTennisBallFramePublisher : public rclcpp::Node
{
public:
  CameraToTennisBallFramePublisher()
  : Node("camera_to_tennis_ball_tf_publisher")
  {
    // Declare and acquire `turtlename` parameter

    // Initialize the transform broadcaster
    tf_broadcaster_ =
      std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    auto handle_tennis_ball_pose = [this](const std::shared_ptr<message_interfaces::msg::TennisBallOrientation> msg){
        geometry_msgs::msg::TransformStamped t;

        t.header.stamp = this->get_clock()->now();
        t.header.frame_id = "link7";
        t.child_frame_id = "tennis_ball_frame";

        t.transform.translation.x = msg->x;
        t.transform.translation.y = msg->y;
        t.transform.translation.z = msg->z;

        t.transform.rotation.x = 0.0;
        t.transform.rotation.y = 0.0;
        t.transform.rotation.z = 0.0;
        t.transform.rotation.w = 1.0;  

        tf_broadcaster_->sendTransform(t);
    };
    tennis_ball_orientation_subscription_ = this->create_subscription<message_interfaces::msg::TennisBallOrientation>(
      "orientation_info", 10,
      handle_tennis_ball_pose);
  }

private:
  rclcpp::Subscription<message_interfaces::msg::TennisBallOrientation>::SharedPtr tennis_ball_orientation_subscription_;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CameraToTennisBallFramePublisher>());
  rclcpp::shutdown();
  return 0;
}