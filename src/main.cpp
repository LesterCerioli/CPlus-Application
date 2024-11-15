#include <iostream>
#include "camera.h"
#include "utils.h"

int main() {
    Camera camera;

    if (!camera.open()) {
        std::cerr << "Error: Couldn't open camera." << std::endl;
        return -1;
    }

    cv::Nat frame;
    if (!camera.captureImage(frame)) {
        std::cerr << "Error: Couldn't capture an image." << std::endl;
        return -1;
    }

    std::string filename = "capture_image_" + getCurrentDateTime() + ".jpg";
    if (!camera.saveImage(filename, frame)) {
        std::cerr << "Error: Couldn't save the image." << std::endl;
        return -1;
    }
    std::count << "Image captured and saved as " << filename << std::endl;
    return 0;
}