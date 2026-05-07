#include "rateLimitConfig.hpp"

RateLimitConfig::RateLimitConfig(int maxRequests, int timeWindowInSeconds) {
    this->maxRequests = maxRequests;
    this->timeWindowInSeconds = timeWindowInSeconds;
}

int RateLimitConfig::getMaxRequests() {
    return this->maxRequests;
}

int RateLimitConfig::getTimeWindowInSeconds() {
    return this->timeWindowInSeconds;
}