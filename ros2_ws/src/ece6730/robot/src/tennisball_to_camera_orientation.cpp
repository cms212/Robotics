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
            //RCLCPP_INFO(this->get_logger(), "Detection: left_x:%d, right_x:%d, top_y:%d, bottom_y:%d", 
                       //msg->left_x, msg->right_x, msg->top_y, msg->bottom_y);
            
            // Validate bounding box
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
            
            float center_x = (msg->left_x + msg->right_x) / 2.0;
            float center_y = (msg->top_y + msg->bottom_y) / 2.0;
            float offset_from_principal_x = center_x - principal_point_x;
            float offset_from_principal_y = center_y - principal_point_y;
            
            //RCLCPP_INFO(this->get_logger(), "Ball center: (%.1f, %.1f) px, Principal point: (%.1f, %.1f) px", 
                       //center_x, center_y, principal_point_x, principal_point_y);
            //RCLCPP_INFO(this->get_logger(), "Offset from principal point: (%.1f, %.1f) px", 
                       //offset_from_principal_x, offset_from_principal_y);
            //RCLCPP_INFO(this->get_logger(), "Tennis ball position - X: %.3f m, Y: %.3f m, Z: %.3f m", x, y, z);
            
            // Calculate pixel size for diagnostic
            //float pixel_width = msg->right_x - msg->left_x;
            //float pixel_height = msg->bottom_y - msg->top_y;
            //RCLCPP_INFO(this->get_logger(), "Bounding box size - Width: %.1f px, Height: %.1f px", pixel_width, pixel_height);
        };

        detection_info_subscription =
        this->create_subscription<message_interfaces::msg::TennisBallDetection>("detection_info", 5, topic_callback);
    }

private:
    rclcpp::Publisher<message_interfaces::msg::TennisBallOrientation>::SharedPtr orientation_publisher_;
    message_interfaces::msg::TennisBallOrientation orientation_msg_;
    rclcpp::Subscription<message_interfaces::msg::TennisBallDetection>::SharedPtr detection_info_subscription;
    float camera_fov_x = 70.42 * (M_PI / 180); // radians
    float camera_fov_y = 43.3 * (M_PI / 180); // radians
    float image_width = 800; // pixels
    float image_height = 440; // pixels
    
   
    float principal_point_x = 400; 
    float principal_point_y = 220; 
    float tennis_ball_width =  .067; // meters
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
        
        float y_camera = -(center_y - principal_point_y) * z / calculateFocalLengthY();
        
        return y_camera;
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