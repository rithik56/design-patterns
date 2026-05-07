#pragma once

#include "rateLimitConfig.hpp"

class RateLimiter {
    protected:
        RateLimitConfig* rateLimitConfig;
    public:
        RateLimiter();
        virtual void setRateLimitConfig(RateLimitConfig* rateLimitConfig) = 0;
        RateLimitConfig* getRateLimitConfig();
        virtual bool allowRequest() = 0;
        virtual RateLimiter* createObject() = 0;
};