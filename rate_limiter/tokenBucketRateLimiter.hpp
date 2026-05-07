#pragma once

#include "rateLimiter.hpp"
#include "chrono"

class TokenBuckerRateLimiter: public RateLimiter {
    private:
        int capacity;
        int tokenBuckets;
        double refillRate;
        chrono::steady_clock::time_point lastRefillTime;
        mutex mtx;
    public:
        TokenBuckerRateLimiter();
        virtual void setRateLimitConfig(RateLimitConfig* rateLimitConfig) override;
        bool allowRequest() override;
        TokenBuckerRateLimiter* createObject() override;
};

