#include "tokenBucketRateLimiter.hpp"

TokenBuckerRateLimiter::TokenBuckerRateLimiter() {
    this->rateLimitConfig = nullptr;
    this->capacity = 0;
    this->tokenBuckets = 0;
    this->refillRate = 0.0;
    this->lastRefillTime = chrono::steady_clock::now();
}

void TokenBuckerRateLimiter::setRateLimitConfig(RateLimitConfig* rateLimitConfig) {
    int maxRequests = rateLimitConfig->getMaxRequests();
    int timeWindowInSeconds = rateLimitConfig->getTimeWindowInSeconds();
    this->capacity = maxRequests;
    this->tokenBuckets = maxRequests;
    this->refillRate = double(maxRequests) / timeWindowInSeconds;
    this->lastRefillTime = chrono::steady_clock::now();
    this->rateLimitConfig = rateLimitConfig;
}

bool TokenBuckerRateLimiter::allowRequest() {
    lock_guard<mutex> lock(this->mtx);
    chrono::steady_clock::time_point currentTime = chrono::steady_clock::now();
    long long int elapsedTime = std::chrono::duration_cast<
        std::chrono::seconds
    >(currentTime - lastRefillTime).count();

    int tokensAdded = this->refillRate * elapsedTime;
    this->tokenBuckets = min(this->capacity, this->tokenBuckets + tokensAdded);
    this->lastRefillTime = currentTime;

    if (this->tokenBuckets > 0) {
        this->tokenBuckets--;
        return true;
    }
    return false;
}

TokenBuckerRateLimiter* TokenBuckerRateLimiter::createObject() {
    return new TokenBuckerRateLimiter();
}