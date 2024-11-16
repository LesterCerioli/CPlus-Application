#include "api_controller.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    ApiController api;
    api.open();
    std::cout << "PhotoAppBackend is running on http://localhost:8080" << std::endl;

    
    std::this_thread::sleep_for(std::chrono::minutes(10));
    api.close();
    return 0;
}
