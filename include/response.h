#ifndef RESPONSE_H
#define RESPONSE_H

#include <vector>
#include <string>
#include <memory>

class Response {
private:
    std::vector<std::string> messages;
    std::shared_ptr<std::vector<std::string>> errors;

public:
    std::shared_ptr<void> result;

    Response();
    Response(std::shared_ptr<void> result);
    Response& AddError(const std::string& message);
    const std::shared_ptr<std::vector<std::string>>& getErrors() const;
};

#endif // RESPONSE_H
