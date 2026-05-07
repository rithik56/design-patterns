#include "rateLimiterService.hpp"

mutex RateLimiterService::mtx;
RateLimiterService* RateLimiterService::rateLimiterService = nullptr;

RateLimiterService* RateLimiterService::getInstance() {
    if (rateLimiterService == nullptr) {
        mtx.lock();
        if (rateLimiterService == nullptr) {
            rateLimiterService = new RateLimiterService();
        }
        mtx.unlock();
    }
    return rateLimiterService;
}

RateLimiterService::RateLimiterService() {
    this->rateLimiterStrategy = nullptr;
}

bool RateLimiterService::handleRequest(int id) {
    return this->rateLimiterMap[id]->allowRequest();
}

void RateLimiterService::setRateLimiter(RateLimiter* rateLimiterStrategy) {
    this->rateLimiterStrategy = rateLimiterStrategy;
}

void RateLimiterService::setUserLimit(int id, RateLimitConfig* rateLimitConfig) {
    RateLimiter* rateLimiterCopy = this->rateLimiterStrategy->createObject();
    this->rateLimiterStrategy->setRateLimitConfig(rateLimitConfig);
    this->rateLimiterMap[id] = this->rateLimiterStrategy;
    this->rateLimiterStrategy = rateLimiterCopy;
}

void RateLimiterService::updateUserLimit(int id, RateLimitConfig* rateLimitConfig) {
    this->rateLimiterMap[id]->setRateLimitConfig(rateLimitConfig);
}
