#include <fstream>
#include <opencv2/opencv.hpp>
#include <onnxruntime_cxx_api.h>
#include <algorithm>
#include <numeric>
#include <sys/stat.h>  // Add this for mkdir

std::vector<std::string> load_class_list()
{
    std::vector<std::string> class_list;
    std::ifstream ifs("../classes.txt");
    std::string line;
    while (getline(ifs, line))
    {
        class_list.push_back(line);
    }
    return class_list;
}

// Add helper function to create directory
bool createDirectory(const std::string& path) {
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

const std::vector<cv::Scalar> colors = {cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 255), cv::Scalar(255, 0, 0)};

const float INPUT_WIDTH = 640.0;
const float INPUT_HEIGHT = 640.0;
const float SCORE_THRESHOLD = 0.2;
const float NMS_THRESHOLD = 0.4;
const float CONFIDENCE_THRESHOLD = 0.4;

struct Detection
{
    int class_id;
    float confidence;
    cv::Rect box;
};

class YOLODetector {
private:
    Ort::Env env;
    Ort::Session session;
    Ort::MemoryInfo memory_info;
    std::vector<const char*> input_names;
    std::vector<const char*> output_names;
    std::vector<int64_t> input_shape;
    
public:
    YOLODetector(const std::string& model_path) 
        : env(ORT_LOGGING_LEVEL_WARNING, "YOLODetector"),
          session(env, model_path.c_str(), Ort::SessionOptions{}),
          memory_info(Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault)) {
        
        // Get input info
        auto input_count = session.GetInputCount();
        for (size_t i = 0; i < input_count; i++) {
            auto input_name = session.GetInputNameAllocated(i, Ort::AllocatorWithDefaultOptions{});
            input_names.push_back(input_name.release());
            
            auto input_shapes = session.GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
            input_shape = input_shapes;
        }
        
        // Get output info
        auto output_count = session.GetOutputCount();
        for (size_t i = 0; i < output_count; i++) {
            auto output_name = session.GetOutputNameAllocated(i, Ort::AllocatorWithDefaultOptions{});
            output_names.push_back(output_name.release());
        }
        
        std::cout << "Model loaded successfully" << std::endl;
        std::cout << "Input shape: ";
        for (auto dim : input_shape) {
            std::cout << dim << " ";
        }
        std::cout << std::endl;
    }
    
    cv::Mat format_image(const cv::Mat &source) {
        int col = source.cols;
        int row = source.rows;
        int _max = std::max(col, row);
        cv::Mat result = cv::Mat::zeros(_max, _max, CV_8UC3);
        source.copyTo(result(cv::Rect(0, 0, col, row)));
        cv::resize(result, result, cv::Size(INPUT_WIDTH, INPUT_HEIGHT));
        return result;
    }
    
    std::vector<Detection> detect(cv::Mat& image) {
        cv::Mat input_image = format_image(image);
        
        // Convert to float and normalize
        cv::Mat blob;
        input_image.convertTo(blob, CV_32F, 1.0/255.0);
        
        // Convert to CHW format
        std::vector<cv::Mat> channels(3);
        cv::split(blob, channels);
        
        // Flatten and combine channels
        std::vector<float> input_tensor_values;
        for (auto& channel : channels) {
            std::vector<float> channel_data = channel.reshape(1, 1);
            input_tensor_values.insert(input_tensor_values.end(), channel_data.begin(), channel_data.end());
        }
        
        // Create input tensor
        std::vector<int64_t> input_tensor_shape = {1, 3, (int64_t)INPUT_HEIGHT, (int64_t)INPUT_WIDTH};
        auto input_tensor = Ort::Value::CreateTensor<float>(
            memory_info, input_tensor_values.data(), input_tensor_values.size(),
            input_tensor_shape.data(), input_tensor_shape.size()
        );
        
        // Run inference
        auto output_tensors = session.Run(Ort::RunOptions{nullptr}, 
                                         input_names.data(), &input_tensor, 1,
                                         output_names.data(), output_names.size());
        
        // Process output
        float* output_data = output_tensors[0].GetTensorMutableData<float>();
        auto output_shape = output_tensors[0].GetTensorTypeAndShapeInfo().GetShape();
        
        // Parse detections
        std::vector<Detection> detections;
        
        // YOLOv11 output format: [batch, features, detections] or [batch, detections, features]
        int num_detections, num_features;
        bool is_transposed = false;
        
        if (output_shape.size() == 3) {
            if (output_shape[1] > output_shape[2] && output_shape[2] >= 4) {
                // [batch, detections, features]
                num_detections = output_shape[1];
                num_features = output_shape[2];
            } else {
                // [batch, features, detections] - transposed
                num_detections = output_shape[2];
                num_features = output_shape[1];
                is_transposed = true;
            }
        } else {
            return detections;
        }
        
        // Calculate the correct scaling factors accounting for padding
        int original_width = image.cols;
        int original_height = image.rows;
        int max_dim = std::max(original_width, original_height);
        
        // The image was padded to max_dim x max_dim, then resized to 640x640
        float scale = (float)max_dim / INPUT_WIDTH;
        
        // Calculate offsets for centering (padding was added to make square)
        float x_offset = 0;
        float y_offset = 0;
        if (original_width < max_dim) {
            x_offset = 0; // Image is copied to top-left, so no x offset
        }
        if (original_height < max_dim) {
            y_offset = 0; // Image is copied to top-left, so no y offset
        }
        
        std::vector<int> class_ids;
        std::vector<float> confidences;
        std::vector<cv::Rect> boxes;
        
        for (int i = 0; i < num_detections; ++i) {
            float x, y, w, h;
            
            if (is_transposed) {
                x = output_data[0 * num_detections + i];
                y = output_data[1 * num_detections + i];
                w = output_data[2 * num_detections + i];
                h = output_data[3 * num_detections + i];
            } else {
                x = output_data[i * num_features + 0];
                y = output_data[i * num_features + 1];
                w = output_data[i * num_features + 2];
                h = output_data[i * num_features + 3];
            }
            
            // Find max class confidence
            float max_confidence = 0;
            int max_class_id = 0;
            for (int j = 4; j < num_features; ++j) {
                float conf;
                if (is_transposed) {
                    conf = output_data[j * num_detections + i];
                } else {
                    conf = output_data[i * num_features + j];
                }
                
                if (conf > max_confidence) {
                    max_confidence = conf;
                    max_class_id = j - 4;
                }
            }
            
            if (max_confidence >= CONFIDENCE_THRESHOLD) {
                // Convert coordinates from 640x640 model output to original image
                // First scale back to the padded square image
                float center_x = x * scale;
                float center_y = y * scale;
                float width = w * scale;
                float height = h * scale;
                
                // Convert from center coordinates to top-left coordinates
                int left = int(center_x - width / 2.0);
                int top = int(center_y - height / 2.0);
                int box_width = int(width);
                int box_height = int(height);
                
                // Clamp to original image bounds
                left = std::max(0, std::min(left, original_width - 1));
                top = std::max(0, std::min(top, original_height - 1));
                box_width = std::min(box_width, original_width - left);
                box_height = std::min(box_height, original_height - top);
                
                if (box_width > 0 && box_height > 0) {
                    boxes.push_back(cv::Rect(left, top, box_width, box_height));
                    confidences.push_back(max_confidence);
                    class_ids.push_back(max_class_id);
                }
            }
        }
        
        // Apply NMS
        std::vector<int> nms_result;
        cv::dnn::NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, nms_result);
        
        for (int i = 0; i < nms_result.size(); i++) {
            int idx = nms_result[i];
            Detection result;
            result.class_id = class_ids[idx];
            result.confidence = confidences[idx];
            result.box = boxes[idx];
            detections.push_back(result);
        }
        
        return detections;
    }
};

int main(int argc, char **argv)
{
    std::vector<std::string> class_list = load_class_list();
    
    // Debug: Print loaded classes
    std::cout << "Loaded " << class_list.size() << " classes:" << std::endl;
    for (size_t i = 0; i < class_list.size(); i++) {
        std::cout << "  " << i << ": " << class_list[i] << std::endl;
    }
    
    try {
        YOLODetector detector("../TennisBalls.onnx");

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