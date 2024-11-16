#include "api_controller.h"
#include "services/capture_service.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    auto captureService = std::make_shared<CaptureService>();
    ApiController api(captureService);
    api.open();
    std::cout << "PhotoAppBackend is running on http://localhost:8080" << std::endl;

    
    std::this_thread::sleep_for(std::chrono::minutes(10));
    api.close();
    return 0;
}
