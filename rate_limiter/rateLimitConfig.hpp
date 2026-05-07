#pragma once

#include "common.hpp"

class RateLimitConfig {
    private:
        int maxRequests;
        int timeWindowInSeconds;
    public:
        RateLimitConfig(int maxRequests, int timeWindowInSeconds);
        int getMaxRequests();
        int getTimeWindowInSeconds();
};