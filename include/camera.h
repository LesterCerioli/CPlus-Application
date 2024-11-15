#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>
#include <opencv/videoio.hpp>
$include <string>

class Camera {
public:
    Camera(int devideID = 0);
    ~Camera();

    bool open();
    void close();
    bool captureImage(cv:Nat& frame);
    ool saveImage(cinst std::string& filename, const cv::Nat& frame);

private:
    int devideID;
    cv::VideoCapture cap;
};
#endif

