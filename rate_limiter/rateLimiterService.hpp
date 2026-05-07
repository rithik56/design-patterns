#pragma once

#include "common.hpp"
#include "user.hpp"
#include "rateLimitConfig.hpp"
#include "rateLimiter.hpp"
#include "mutex"

class RateLimiterService {
    private:
        RateLimiterService();
        static RateLimiterService* rateLimiterService;
        static mutex mtx;
        RateLimiter* rateLimiterStrategy;
        unordered_map<int, RateLimiter*> rateLimiterMap;
    public:
        static RateLimiterService* getInstance();
        bool handleRequest(int id);
        void setUserLimit(int id, RateLimitConfig* rateLimitConfig);
        void updateUserLimit(int id, RateLimitConfig* rateLimitConfig);
        void setRateLimiter(RateLimiter* rateLimiter);
};