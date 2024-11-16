#include "api_controller.h"
#include <iostream>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

ApiController::ApiController(std::shared_ptr<ICaptureService> captureService) 
    : captureService(captureService) {
    listener = http_listener(U("http://localhost:8080"));
    listener.support(methods::POST, std::bind(&ApiController::handle_post, this, std::placeholders::_1));
    listener.support(methods::GET, std::bind(&ApiController::handle_get, this, std::placeholders::_1));
}

void ApiController::handle_post(http_request request) {
    request.extract_json().then([this, request](json::value requestBody) {
        if (!requestBody.has_field(U("photo_data"))) {
            send_response(request, status_codes::BadRequest, U("Missing 'photo_data' field."));
            return;
        }

        std::string data = requestBody[U("photo_data")].as_string();
        auto futureResult = captureService->capturePhotoAsync(data);

        try {
            auto result = futureResult.get();
            auto response = json::value::object();
            response[U("message")] = json::value::string(U(result));
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
