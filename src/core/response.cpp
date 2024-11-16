#include "response.h"

Response::Response() : errors(std::make_shared<std::vector<std::string>>(messages)) {}

Response::Response(std::shared_ptr<void> result) : Response() {
    this->result = result;
}

Response& Response::AddError(const std::string& message) {
    messages.push_back(message);
    return *this;
}

const std::shared_ptr<std::vector<std::string>>& Response::getErrors() const {
    return errors;
}
