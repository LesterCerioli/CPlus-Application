#ifndef CAPTURE_SERVICE_H
#define CAPTURE_SERVICE_H

#include "icapture_service.h"
#include <opencv2/opencv.hpp>
#include <string>
#include <future>

class CaptureService : public ICaptureService {
public:
    std::future<std::string> capturePhotoAsync(const std::string& data) override;
};

#endif // CAPTURE_SERVICE_H
