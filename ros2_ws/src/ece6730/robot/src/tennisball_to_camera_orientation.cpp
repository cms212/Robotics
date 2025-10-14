#include <memory>

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
        detection_info_subscription =
        this->create_subscription<message_interfaces::msg::TennisBallDetection>("detection_info", 5, topic_callback);
    }

private:
    rclcpp::Subscription<message_interfaces::msg::TennisBallDetection>::SharedPtr detection_info_subscription;
    private float camera_fov = 70.42; 

    private float processX(){

    }
    private float processY(){

    }
    private float processZ(){
    
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DetectionInfoSubscriber>());
    rclcpp::shutdown();
    return 0;
}