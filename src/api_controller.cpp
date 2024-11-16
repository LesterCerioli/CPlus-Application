#include "api_controller.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

ApiController::ApiController() {
    listener = http_listener(U("http://localhost:8080"));
    listener.support(methods::POST, std::bind(&ApiController::handle_post, this, std::placeholders::_1));
    listener.support(methods::GET, std::bind(&ApiController::handle_get, this, std::placeholders::_1));
}

void ApiController::handle_post(http_request request) {
    request.extract_json().then([&](json::value requestBody) {
        
        if (!requestBody.has_field(U("photo_data"))) {
            send_response(request, status_codes::BadRequest, U("Missing 'photo_data' field."));
            return;
        }

        try {
            auto response = json::value::object();

            
            Mat image = Mat::zeros(480, 640, CV_8UC3);
            putText(image, "PhotoAppBackend Capture", Point(50, 240), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);

            imwrite("captured_photo.jpg", image);

            response[U("message")] = json::value::string(U("Photo captured successfully."));
            request.reply(status_codes::Created, response); // 201 Created
        } catch (const std::exception& e) {
            send_response(request, status_codes::InternalError, U("Internal server error occurred."));
        }
    }).wait();
}

void ApiController::handle_get(http_request request) {
    auto response = json::value::object();
    response[U("message")] = json::value::string(U("Welcome to PhotoAppBackend!"));
    request.reply(status_codes::OK, response); // 200 OK
}

void ApiController::send_response(http_request request, status_code code, const utility::string_t& message) {
    auto response = json::value::object();
    response[U("message")] = json::value::string(message);
    request.reply(code, response);
}

void ApiController::open() {
    listener.open().wait();
}

void ApiController::close() {
    listener.close().wait();
}
