#include <memory>
#include <cmath>
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/tennis_ball_detection.hpp"
#include "message_interfaces/msg/tennis_ball_orientation.hpp"



class TennisBallPositionPublisher : public rclcpp::Node
{
public:
    TennisBallPositionPublisher()
    : Node("tennis_ball_position_publisher")
    {
        orientation_publisher_ = this->create_publisher<message_interfaces::msg::TennisBallOrientation>("orientation_info", 10);
        auto topic_callback =
        [this](message_interfaces::msg::TennisBallDetection::UniquePtr msg) -> void {
            
            if (msg->left_x >= msg->right_x || msg->top_y >= msg->bottom_y) {
                RCLCPP_WARN(this->get_logger(), "Invalid bounding box detected");
                return;
            }
            
            z = processZ(*msg);
            x = processX(*msg);
            y = processY(*msg);

            orientation_msg_.x = x;
            orientation_msg_.y = y;
            orientation_msg_.z = z;
            orientation_publisher_->publish(orientation_msg_);
        };

        detection_info_subscription =
        this->create_subscription<message_interfaces::msg::TennisBallDetection>("detection_info", 5, topic_callback);
    }

private:
    rclcpp::Publisher<message_interfaces::msg::TennisBallOrientation>::SharedPtr orientation_publisher_;
    message_interfaces::msg::TennisBallOrientation orientation_msg_;
    rclcpp::Subscription<message_interfaces::msg::TennisBallDetection>::SharedPtr detection_info_subscription;
    float camera_fov_x = 70.42 * (M_PI / 180); 
    float camera_fov_y = 43.3 * (M_PI / 180); 
    float image_width = 800; 
    float image_height = 440; 
    float principal_point_x = 400; 
    float principal_point_y = 220; 
    float tennis_ball_width =  .067; 
    float x;
    float y;
    float z;

    float processX(message_interfaces::msg::TennisBallDetection& msg){
        float z = processZ(msg);
        float center_x = (msg.left_x + msg.right_x) / 2.0;
        
        float x_camera = (center_x - principal_point_x) * z / calculateFocalLengthX();
        
        return -x_camera;
    }
    float processY(message_interfaces::msg::TennisBallDetection& msg){
        float z = processZ(msg);
        float center_y = (msg.top_y + msg.bottom_y) / 2.0;
        
        float y_camera = (center_y - principal_point_y) * z / calculateFocalLengthY();
        
        return -y_camera;
    }
    float processZ(message_interfaces::msg::TennisBallDetection& msg){
        float x_focal_length = calculateFocalLengthX();
        float y_focal_length = calculateFocalLengthY();
        
        float ball_pixel_width = msg.right_x - msg.left_x;
        float ball_pixel_height = msg.bottom_y - msg.top_y;
        
        float z_from_width = (tennis_ball_width * x_focal_length) / ball_pixel_width;
        float z_from_height = (tennis_ball_width * y_focal_length) / ball_pixel_height;
        
        float z_average = (z_from_width + z_from_height) / 2.0;
        
        return z_average;
    }
    float calculateFocalLengthX(){
        return (image_width / 2) / tan(camera_fov_x / 2);
    }
    float calculateFocalLengthY(){
        return (image_height / 2) / tan(camera_fov_y / 2);
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TennisBallPositionPublisher>());
    rclcpp::shutdown();
    return 0;
}