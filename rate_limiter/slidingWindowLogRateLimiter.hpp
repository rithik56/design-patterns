#pragma once

#include "rateLimiter.hpp"
#include "chrono"
#include "mutex"

class SlidingWindowLogRateLimiter: public RateLimiter {
    private:
        queue<chrono::steady_clock::time_point> activeRequestQueue;
        mutex mtx;
    public:
        SlidingWindowLogRateLimiter();
        virtual void setRateLimitConfig(RateLimitConfig* rateLimitConfig) override;
        bool allowRequest() override;
        SlidingWindowLogRateLimiter* createObject() override;
};

