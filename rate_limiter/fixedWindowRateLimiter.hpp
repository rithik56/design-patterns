#pragma once

#include "rateLimiter.hpp"
#include "chrono"
#include "mutex"

class FixedWindowRateLimiter: public RateLimiter {
    private:
        chrono::steady_clock::time_point windowStartTime;
        int windowCounter;
        mutex mtx;
    public:
        FixedWindowRateLimiter();
        virtual void setRateLimitConfig(RateLimitConfig* rateLimitConfig) override;
        bool allowRequest() override;
        FixedWindowRateLimiter* createObject() override;
};

