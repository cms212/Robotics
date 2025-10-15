#include <memory>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/tennis_ball_detection.hpp"



class DetectionInfoSubscriber : public rclcpp::Node
{
public:
    DetectionInfoSubscriber()
    : Node("detection_info_subscriber")
    {
        auto topic_callback =
        [this](message_interfaces::msg::TennisBallDetection::UniquePtr msg) -> void {
            RCLCPP_INFO(this->get_logger(), "I heard: 'left_x:%d /n right_x:%d /n top_y:%d /n bottom_y:%d'", msg->left_x, msg->right_x, msg->top_y, msg->bottom_y);
        };

        auto distance_processing_callback =
        [this](message_interfaces::msg::TennisBallDetection::UniquePtr msg) -> void {
            float r = 
            x = processX(*msg);
            y = processY(*msg);
            z = processZ(*msg);
            RCLCPP_INFO(this->get_logger(), "x: %f, y: %f, z: %f", x, y, z);
        };

        detection_info_subscription =
        this->create_subscription<message_interfaces::msg::TennisBallDetection>("detection_info", 5, topic_callback);
    }

private:
    rclcpp::Subscription<message_interfaces::msg::TennisBallDetection>::SharedPtr detection_info_subscription;
    float camera_fov_x = 70.42 * (M_PI / 180); // radians
    float camera_fov_y = 43.3 * (M_PI / 180); // radians
    float image_width = 640.0; // pixels
    float image_height = 640.0; // pixels
    float tennis_ball_width =  .067; // meters
    float x;
    float y;
    float z;
    float processX(message_interfaces::msg::TennisBallDetection& msg){
        float z = processZ(msg);
        float temp = (((msg.left_x + msg.right_x) / 2.0) - (image_width / 2.0))/calculateFocalLengthX();
        return temp * z;
    }
    float processY(message_interfaces::msg::TennisBallDetection& msg){
        float z = processZ(msg);
        float temp = (((msg.top_y + msg.bottom_y) / 2.0) - (image_height / 2.0))/calculateFocalLengthY();
        return temp * z;
    }
    float processZ(message_interfaces::msg::TennisBallDetection& msg){
        float x_focal_length = calculateFocalLengthX();
        float ball_pixel_width = msg.right_x - msg.left_x;
        return (tennis_ball_width * x_focal_length) / ball_pixel_width;
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
    rclcpp::spin(std::make_shared<DetectionInfoSubscriber>());
    rclcpp::shutdown();
    return 0;
}