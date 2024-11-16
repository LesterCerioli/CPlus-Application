#ifndef API_CONTROLLER_H
#define API_CONTROLLER_H


#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "services/icapture_service.h"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class ApiController {
public:
    ApiController();
    void handle_post(http_request request);
    void handle_get(http_request request);
    void open();
    void close();
private:
    http_listener listener;
    std::shared_ptr<ICaptureService> captureService;
    void send_response(http_request request, status_code code, const utility::string_t& message);
};

#endif // API_CONTROLLER_H
