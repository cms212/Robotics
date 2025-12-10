#ifndef YOLO_DETECTOR_H
#define YOLO_DETECTOR_H

#include <fstream>
#include <opencv2/opencv.hpp>
#include <onnxruntime_cxx_api.h>
#include <algorithm>
#include <numeric>
#include <sys/stat.h> 

const float INPUT_WIDTH = 640.0;
const float INPUT_HEIGHT = 640.0;
const float SCORE_THRESHOLD = 0.2;
const float NMS_THRESHOLD = 0.4;
const float CONFIDENCE_THRESHOLD = 0.60;

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
        
        auto input_count = session.GetInputCount();
        for (size_t i = 0; i < input_count; i++) {
            auto input_name = session.GetInputNameAllocated(i, Ort::AllocatorWithDefaultOptions{});
            input_names.push_back(input_name.release());
            
            auto input_shapes = session.GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
            input_shape = input_shapes;
        }
        
        auto output_count = session.GetOutputCount();
        for (size_t i = 0; i < output_count; i++) {
            auto output_name = session.GetOutputNameAllocated(i, Ort::AllocatorWithDefaultOptions{});
            output_names.push_back(output_name.release());
        }
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
        
        cv::Mat blob;
        input_image.convertTo(blob, CV_32F, 1.0/255.0);
        
        std::vector<cv::Mat> channels(3);
        cv::split(blob, channels);
        
        std::vector<float> input_tensor_values;
        for (auto& channel : channels) {
            std::vector<float> channel_data = channel.reshape(1, 1);
            input_tensor_values.insert(input_tensor_values.end(), channel_data.begin(), channel_data.end());
        }
        
        std::vector<int64_t> input_tensor_shape = {1, 3, (int64_t)INPUT_HEIGHT, (int64_t)INPUT_WIDTH};
        auto input_tensor = Ort::Value::CreateTensor<float>(
            memory_info, input_tensor_values.data(), input_tensor_values.size(),
            input_tensor_shape.data(), input_tensor_shape.size()
        );
        
        auto output_tensors = session.Run(Ort::RunOptions{nullptr}, 
                                         input_names.data(), &input_tensor, 1,
                                         output_names.data(), output_names.size());
        
        float* output_data = output_tensors[0].GetTensorMutableData<float>();
        auto output_shape = output_tensors[0].GetTensorTypeAndShapeInfo().GetShape();
        
        std::vector<Detection> detections;
        
        int num_detections, num_features;
        bool is_transposed = false;
        
        if (output_shape.size() == 3) {
            if (output_shape[1] > output_shape[2] && output_shape[2] >= 4) {
                num_detections = output_shape[1];
                num_features = output_shape[2];
            } else {
                num_detections = output_shape[2];
                num_features = output_shape[1];
                is_transposed = true;
            }
        } else {
            return detections;
        }
        
        int original_width = image.cols;
        int original_height = image.rows;
        int max_dim = std::max(original_width, original_height);
        
        float scale = (float)max_dim / INPUT_WIDTH;
        
        float x_offset = 0;
        float y_offset = 0;
        if (original_width < max_dim) {
            x_offset = 0; 
        }
        if (original_height < max_dim) {
            y_offset = 0; 
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
                float center_x = x * scale;
                float center_y = y * scale;
                float width = w * scale;
                float height = h * scale;
                
                int left = int(center_x - width / 2.0);
                int top = int(center_y - height / 2.0);
                int box_width = int(width);
                int box_height = int(height);
                
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


#endif
