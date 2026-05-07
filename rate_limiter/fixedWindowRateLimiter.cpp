#include "fixedWindowRateLimiter.hpp"

FixedWindowRateLimiter::FixedWindowRateLimiter() {
    this->rateLimitConfig = nullptr;
    this->windowStartTime = chrono::steady_clock::now();
    this->windowCounter = 0;
}

void FixedWindowRateLimiter::setRateLimitConfig(RateLimitConfig* rateLimitConfig) {
    this->rateLimitConfig = rateLimitConfig;
}

bool FixedWindowRateLimiter::allowRequest() {
    lock_guard<mutex> lock(this->mtx);
    chrono::steady_clock::time_point currentTime = chrono::steady_clock::now();
    long long int elapsedTime = chrono::duration_cast<
        chrono::seconds
    >(currentTime - this->windowStartTime).count();
    int maxRequests = rateLimitConfig->getMaxRequests();
    int timeWindowInSeconds = rateLimitConfig->getTimeWindowInSeconds();
    if (elapsedTime < timeWindowInSeconds) {
        if (this->windowCounter < maxRequests) {
            this->windowCounter++;
            return true;
        }
        return false;
    }
    this->windowStartTime = currentTime;
    this->windowCounter = 1;
    return true;
}

FixedWindowRateLimiter* FixedWindowRateLimiter::createObject() {
    return new FixedWindowRateLimiter();
}