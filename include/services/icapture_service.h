
#ifndef ICAPTURE_SERVICE_H
#define ICAPTURE_SERVICE_H

#include <string>
#include <future>

class ICaptureService {
public:
    virtual ~ICaptureService();
    virtual std::future<std::string> capturePhotoAsync(const std::string& data) = 0;
};
#endif