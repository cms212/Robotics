#include <opencv2/opencv.hpp>
#include <iostream>

// HSV threshold trackbar values
int h_low = 12, s_low = 80, v_low = 60;
int h_high = 25, s_high = 200, v_high = 180;

int main() {
    // Open default camera
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    cv::Mat frame, hsv, mask;

    // Create trackbars window
    cv::namedWindow("Trackbars", cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("H Low",  "Trackbars", &h_low, 179);
    cv::createTrackbar("H High", "Trackbars", &h_high, 179);
    cv::createTrackbar("S Low",  "Trackbars", &s_low, 255);
    cv::createTrackbar("S High", "Trackbars", &s_high, 255);
    cv::createTrackbar("V Low",  "Trackbars", &v_low, 255);
    cv::createTrackbar("V High", "Trackbars", &v_high, 255);

    bool eggPreviouslyDetected = false;

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // Convert to HSV and blur
        cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
        cv::GaussianBlur(hsv, hsv, cv::Size(5, 5), 0);

        // Threshold based on trackbar values
        cv::inRange(hsv, cv::Scalar(h_low, s_low, v_low),
                         cv::Scalar(h_high, s_high, v_high), mask);

        // Morphological cleanup
        cv::morphologyEx(mask, mask, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1,-1), 2);
        cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, cv::Mat(), cv::Point(-1,-1), 2);

        // Find contours
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        bool eggFound = false;

        for (auto &contour : contours) {
            if (contour.size() >= 5) { // required for fitEllipse
                cv::RotatedRect ellipse = cv::fitEllipse(contour);

                // Egg-like aspect ratio
                float aspect = (float)ellipse.size.height / ellipse.size.width;
                if (aspect > 1.2 && aspect < 2.0) {
                    cv::ellipse(frame, ellipse, cv::Scalar(0, 255, 0), 2);
                    eggFound = true;
                }
            }
        }

        // Trigger signal only on NEW detection
        if (eggFound && !eggPreviouslyDetected) {
            std::cout << "✅ Egg detected!" << std::endl;
        }

        eggPreviouslyDetected = eggFound;

        // Show results
        cv::imshow("Mask", mask);
        cv::imshow("Egg Detection", frame);

        // Exit on 'q'
        if (cv::waitKey(30) == 'q') break;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}

