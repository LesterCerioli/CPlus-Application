#include "services/capture_service.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

std::future<std::string> CaptureService::capturePhotoAsync(const std::string& data) {
    return std::async(std::launch::async, [data]() {
        try {
            Mat image = Mat::zeros(480, 640, CV_8UC3);
            putText(image, data, Point(50, 240), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
            
            std::string fileName = "captured_photo.jpg";
            imwrite(fileName, image);

            return std::string("Photo captured successfully.");
        } catch (const std::exception& e) {
            std::cerr << "Error capturing photo: " << e.what() << std::endl;
            return std::string("Error capturing photo.");
        }
    });
}
