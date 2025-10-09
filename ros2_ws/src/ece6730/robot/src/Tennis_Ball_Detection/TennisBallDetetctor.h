#ifndef TENNIS_BALL_DETECTOR_H
#define TENNIS_BALL_DETECTOR_H

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

// Forward declaration
class YOLODetector;

class TennisBallDetector {
    public:
        TennisBallDetector();
        ~TennisBallDetector();
        std::vector<std::string> load_class_list();
        bool createDirectory(const std::string& path);
        int run();
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
        
    private:

};


#endif