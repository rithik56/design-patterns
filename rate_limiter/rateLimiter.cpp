#include "rateLimiter.hpp"

RateLimiter::RateLimiter() {
}

void RateLimiter::setRateLimitConfig(RateLimitConfig* rateLimitConfig) {
    this->rateLimitConfig = rateLimitConfig;
}

RateLimitConfig* RateLimiter::getRateLimitConfig() {
    return this->rateLimitConfig;
}