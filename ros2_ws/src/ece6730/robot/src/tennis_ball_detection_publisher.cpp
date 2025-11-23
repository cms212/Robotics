#include "Tennis_Ball_Detection/YOLODetector.h"

#include <chrono>
#include <memory>
#include <string>
#include <opencv2/opencv.hpp>

#include "rclcpp/rclcpp.hpp"
#include "message_interfaces/msg/tennis_ball_detection.hpp"


using namespace std::chrono_literals;

class TennisBallDetectorPublisher : public rclcpp::Node
{
public:
  TennisBallDetectorPublisher()
  : Node("tennis_ball_detector_publisher")
  {
    // Allow optionally showing the camera window; default is false (no window)
    show_window_ = this->declare_parameter("show_camera_window", false);
    publisher = this->create_publisher<message_interfaces::msg::TennisBallDetection>("detection_info", 10);
    // Initialize camera
    cap_.open(0);
    if (!cap_.isOpened()) {
      RCLCPP_ERROR(this->get_logger(), "Cannot open camera");
      return;
    }

    class_list_ = load_class_list();
    
      try {
        std::string model_path = "src/ece6730/robot/src/config/TennisBalls.onnx";
        detector_ = std::make_unique<YOLODetector>(model_path);
        //RCLCPP_INFO(this->get_logger(), "YOLO detector initialized successfully");
      } catch (const std::exception& e) {
      //RCLCPP_ERROR(this->get_logger(), "Failed to initialize YOLO detector: %s", e.what());
      return;
    }

    timer_ = this->create_wall_timer(
      100ms, std::bind(&TennisBallDetectorPublisher::process_frame, this));

    //RCLCPP_INFO(this->get_logger(), "Tennis Ball Detector Node started");
  }

  ~TennisBallDetectorPublisher()
  {
    if (cap_.isOpened()) {
      cap_.release();
    }
    if (show_window_) {
      cv::destroyAllWindows();
    }
  }

private:
  void process_frame()
  {
    cv::Mat frame;
    cap_ >> frame;
    
    if (frame.empty()) {
      RCLCPP_WARN(this->get_logger(), "Empty frame received");
      return;
    }

    auto detections = detector_->detect(frame);
    
    const std::vector<cv::Scalar> colors = {
      cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), 
      cv::Scalar(0, 255, 255), cv::Scalar(255, 0, 0)
    };
    
    for (auto &detection : detections) {
        // Draw bounding box
        //RCLCPP_INFO(this->get_logger(), "%d", detections.size());
        cv::Scalar box_color = colors[detection.class_id % colors.size()];
        cv::rectangle(frame, detection.box, box_color, 2);
      
        // Create label
        std::string class_name = "Unknown";
        if (detection.class_id >= 0 && detection.class_id < static_cast<int>(class_list_.size())) {
            class_name = class_list_[detection.class_id];
        }
      
        std::string confidence_str = cv::format("%.1f%%", detection.confidence * 100);
        std::string label = class_name + " " + confidence_str;
      
        // Draw label background and text
        int baseline;
        cv::Size label_size = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.6, 1, &baseline);
        int top = std::max(detection.box.y, label_size.height + 5);
      
        cv::rectangle(frame, 
                    cv::Point(detection.box.x, top - label_size.height - 5),
                    cv::Point(detection.box.x + label_size.width + 5, top + baseline), 
                    box_color, cv::FILLED);
      
        cv::putText(frame, label, 
                    cv::Point(detection.box.x + 2, top - 2), 
                    cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 255, 255), 1);
        
        message_interfaces::msg::TennisBallDetection detection_msg;
        detection_msg.left_x = static_cast<uint16_t>(detection.box.x);
        detection_msg.right_x = static_cast<uint16_t>(detection.box.x + detection.box.width);
        detection_msg.top_y = static_cast<uint16_t>(detection.box.y);
        detection_msg.bottom_y = static_cast<uint16_t>(detection.box.y + detection.box.height);
        
        publisher->publish(detection_msg);
    }

    if (show_window_) {
      cv::imshow("Tennis Ball Detection", frame);
      cv::waitKey(1);
    }
  }

  std::vector<std::string> load_class_list()
  {
    std::vector<std::string> class_list;
    std::string classes_path = "src/ece6730/robot/src/config/classes.txt";
    std::ifstream ifs(classes_path);
    std::string line;
    while (getline(ifs, line))
    {
      class_list.push_back(line);
    }
    return class_list;
  }

  cv::VideoCapture cap_;
  std::unique_ptr<YOLODetector> detector_;
  std::vector<std::string> class_list_;
  rclcpp::TimerBase::SharedPtr timer_;
  bool detecting_TennisBalls = true;
  bool detecting_HouseholdItems = false;
  rclcpp::Publisher<message_interfaces::msg::TennisBallDetection>::SharedPtr publisher;
  message_interfaces::msg::TennisBallDetection message;
  bool show_window_ = false;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TennisBallDetectorPublisher>());
  rclcpp::shutdown();
  return 0;
}
       
