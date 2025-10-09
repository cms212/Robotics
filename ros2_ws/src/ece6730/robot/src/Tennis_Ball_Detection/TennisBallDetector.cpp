#include "TennisBallDetetctor.h"
#include <fstream>
#include <opencv2/opencv.hpp>
#include <onnxruntime_cxx_api.h>
#include <algorithm>
#include <numeric>
#include <sys/stat.h>

#include "YOLODetector.h"

TennisBallDetector::TennisBallDetector() {
    // Constructor implementation
}

TennisBallDetector::~TennisBallDetector() {
    // Destructor implementation
}

std::vector<std::string> TennisBallDetector::load_class_list(){
    std::vector<std::string> class_list;
    std::ifstream ifs("../config/classes.txt");
    std::string line;
    while (getline(ifs, line))
    {
        class_list.push_back(line);
    }
    return class_list;
}

bool TennisBallDetector::createDirectory(const std::string& path) {
    struct stat info;
    if (stat(path.c_str(), &info) != 0) {
        // Directory doesn't exist, try to create it
        return mkdir(path.c_str(), 0755) == 0;
    } else if (info.st_mode & S_IFDIR) {
        // Directory already exists
        return true;
    }
    return false;
}

int TennisBallDetector::run(){
    
    std::vector<std::string> class_list = load_class_list();
    
    // Debug: Print loaded classes
    std::cout << "Loaded " << class_list.size() << " classes:" << std::endl;
    for (size_t i = 0; i < class_list.size(); i++) {
        std::cout << "  " << i << ": " << class_list[i] << std::endl;
    }
    
    try {
        YOLODetector detector("../config/TennisBalls.onnx");

        // Instead of a single image lets do video from my camera and then draw boxes on the video
        
        // Open camera (0 is default camera)
        cv::VideoCapture cap(0);
        if (!cap.isOpened()) {
            std::cout << "Error: Cannot open camera" << std::endl;
            return -1;
        }
        
        // Get camera properties
        int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
        int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
        double fps = cap.get(cv::CAP_PROP_FPS);
        if (fps <= 0) fps = 30; // Default to 30 FPS if unable to get camera FPS
        
        std::cout << "Camera opened: " << frame_width << "x" << frame_height << " at " << fps << " FPS" << std::endl;
        
        // Create video writer to save output (optional)
        cv::VideoWriter video_writer;
        bool save_video = true; // Set to false if you don't want to save video
        
        if (save_video) {
            // Create Results directory if it doesn't exist
            if (!createDirectory("../Results")) {
                std::cout << "Warning: Could not create Results directory" << std::endl;
            }
            
            std::string output_video = "../Results/Tennis_Ball_detection_output.mp4";
            int fourcc = cv::VideoWriter::fourcc('m', 'p', '4', 'v');
            video_writer.open(output_video, fourcc, fps, cv::Size(frame_width, frame_height));
            
            if (!video_writer.isOpened()) {
                std::cout << "Error: Cannot create video writer" << std::endl;
                save_video = false;
            } else {
                std::cout << "Saving video to: " << output_video << std::endl;
            }
        }
        
        std::cout << "Press 'q' to quit, 's' to save current frame" << std::endl;
        
        cv::Mat frame;
        int frame_count = 0;
        
        while (true) {
            // Capture frame
            cap >> frame;
            if (frame.empty()) {
                std::cout << "Error: Cannot read frame from camera" << std::endl;
                break;
            }
            
            // Detect objects
            auto detections = detector.detect(frame);
            
            // Draw detections with improved labels
            for (auto &detection : detections) {
                // Draw bounding box
                cv::Scalar box_color = colors[detection.class_id % colors.size()];
                cv::rectangle(frame, detection.box, box_color, 2);
                
                // Create detailed label with class name and confidence
                std::string class_name = "Unknown";
                if (detection.class_id >= 0 && detection.class_id < class_list.size()) {
                    class_name = class_list[detection.class_id];
                } else {
                    class_name = "Class_" + std::to_string(detection.class_id);
                }
                
                std::string confidence_str = cv::format("%.1f%%", detection.confidence * 100);
                std::string label = class_name + " " + confidence_str;
                
                // Enhanced console output with bounding box coordinates
                std::cout << "Detection: " << class_name 
                         << " (ID: " << detection.class_id << ")" 
                         << " Confidence: " << confidence_str 
                         << " Box: [" << detection.box.x << "," << detection.box.y 
                         << "," << detection.box.width << "," << detection.box.height << "]"
                         << std::endl;
                
                // Calculate label background size
                int baseline;
                cv::Size label_size = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.6, 1, &baseline);
                int top = std::max(detection.box.y, label_size.height + 5);
                
                // Draw label background
                cv::rectangle(frame, 
                            cv::Point(detection.box.x, top - label_size.height - 5),
                            cv::Point(detection.box.x + label_size.width + 5, top + baseline), 
                            box_color, cv::FILLED);
                
                // Draw label text
                cv::putText(frame, label, 
                           cv::Point(detection.box.x + 2, top - 2), 
                           cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 255, 255), 1);
            }
            
            // Add detection counter and class summary
            std::string detection_text = "Detections: " + std::to_string(detections.size());
            cv::putText(frame, detection_text, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);
            
            // Add class breakdown
            std::map<std::string, int> class_counts;
            for (const auto& detection : detections) {
                std::string class_name = "Unknown";
                if (detection.class_id >= 0 && detection.class_id < class_list.size()) {
                    class_name = class_list[detection.class_id];
                }
                class_counts[class_name]++;
            }
            
            int y_offset = 60;
            for (const auto& pair : class_counts) {
                std::string count_text = pair.first + ": " + std::to_string(pair.second);
                cv::putText(frame, count_text, cv::Point(10, y_offset), cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(0, 255, 0), 2);
                y_offset += 30;
            }
            
            // Save frame to video if enabled
            if (save_video && video_writer.isOpened()) {
                video_writer.write(frame);
            }
            
            // Display frame
            cv::imshow("Tennis Ball Detection", frame);
            
            // Handle key presses
            char key = cv::waitKey(1) & 0xFF;
            if (key == 'q' || key == 27) { // 'q' or ESC to quit
                break;
            } else if (key == 's') { // 's' to save current frame
                std::string filename = "../Results/frame_" + std::to_string(frame_count++) + ".jpg";
                cv::imwrite(filename, frame);
                std::cout << "Frame saved to " << filename << std::endl;
            }
        }
        
        // Release resources
        cap.release();
        if (video_writer.isOpened()) {
            video_writer.release();
            std::cout << "Video saved successfully" << std::endl;
        }
        cv::destroyAllWindows();
        std::cout << "Camera closed" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}

