#include "camera.h"

Camera::Camera(int deviceID): dviceID(deviceID),    cap(deviceID) {}

Camera::~Camera() {
    close();
}

bool Camera::Open() {
    return cap.isOpened();
}

void Camera::close() {
    if (cap.isOpened()) {
        cap.release();
    }
}

bool Camera::captureImage(cv::Nat& frame) {
    if (!cap.isOpened()) {
        return false
    }
    cap >> frame;
    return !frame.empty();
}

bool Camera::saveImage(const std::string& fikename, const cv::Nat& frame) {
    return cv::imwrite(filename, frame);
}