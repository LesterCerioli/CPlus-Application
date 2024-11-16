#ifndef FAIL_FAST_REQUEST_BEHAVIOR_H
#define FAIL_FAST_REQUEST_BEHAVIOR_H

#include <vector>
#include <functional>
#include <future>
#include <memory>
#include "response.h"

template <typename TRequest>
class IValidator {
public:
    virtual std::vector<ValidationFailure> Validate(const TRequest& request) = 0;
};

template <typename TRequest, typename TResponse>
class IPipelineBehavior {
public:
    virtual std::future<TResponse> Handle(
        const TRequest& request,
        std::function<std::future<TResponse>()> next) = 0;
};

template <typename TRequest, typename TResponse>
class FailFastRequestBehavior : public IPipelineBehavior<TRequest, TResponse> {
private:
    std::vector<std::shared_ptr<IValidator<TRequest>>> validators;

    static std::future<TResponse> Errors(const std::vector<ValidationFailure>& failures) {
        auto response = std::make_shared<Response>();
        for (const auto& failure : failures) {
            response->AddError(failure.ErrorMessage);
        }
        return std::async(std::launch::async, [response]() {
            return *response;
        });
    }

public:
    FailFastRequestBehavior(const std::vector<std::shared_ptr<IValidator<TRequest>>>& validators);

    std::future<TResponse> Handle(
        const TRequest& request,
        std::function<std::future<TResponse>()> next) override;
};

#include "fail_fast_request_behavior.tpp"

#endif // FAIL_FAST_REQUEST_BEHAVIOR_H
