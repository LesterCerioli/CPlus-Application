#ifndef FAIL_FAST_REQUEST_BEHAVIOR_TPP
#define FAIL_FAST_REQUEST_BEHAVIOR_TPP

#include "fail_fast_request_behavior.h"

template <typename TRequest, typename TResponse>
FailFastRequestBehavior<TRequest, TResponse>::FailFastRequestBehavior(
    const std::vector<std::shared_ptr<IValidator<TRequest>>>& validators)
    : validators(validators) {}

template <typename TRequest, typename TResponse>
std::future<TResponse> FailFastRequestBehavior<TRequest, TResponse>::Handle(
    const TRequest& request,
    std::function<std::future<TResponse>()> next) {
    std::vector<ValidationFailure> failures;
    for (const auto& validator : validators) {
        auto result = validator->Validate(request);
        failures.insert(failures.end(), result.begin(), result.end());
    }

    if (!failures.empty()) {
        return Errors(failures);
    } else {
        return next();
    }
}

#endif // FAIL_FAST_REQUEST_BEHAVIOR_TPP
