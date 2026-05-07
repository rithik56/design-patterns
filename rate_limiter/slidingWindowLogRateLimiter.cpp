#include "slidingWindowLogRateLimiter.hpp"

SlidingWindowLogRateLimiter::SlidingWindowLogRateLimiter()
{
    this->rateLimitConfig = nullptr;
}

void SlidingWindowLogRateLimiter::setRateLimitConfig(RateLimitConfig *rateLimitConfig)
{
    this->rateLimitConfig = rateLimitConfig;
}

bool SlidingWindowLogRateLimiter::allowRequest()
{
    lock_guard<mutex> lock(this->mtx);
    chrono::steady_clock::time_point currentTime = chrono::steady_clock::now();
    int maxRequests = rateLimitConfig->getMaxRequests();
    int timeWindowInSeconds = rateLimitConfig->getTimeWindowInSeconds();
    while (!this->activeRequestQueue.empty() && chrono::duration_cast<
                                                      chrono::seconds>(currentTime - this->activeRequestQueue.front())
                                                          .count() >= timeWindowInSeconds)
    {
        this->activeRequestQueue.pop();
    }
    if (this->activeRequestQueue.size() < maxRequests)
    {
        this->activeRequestQueue.push(currentTime);
        return true;
    }
    return false;
}

SlidingWindowLogRateLimiter *SlidingWindowLogRateLimiter::createObject()
{
    return new SlidingWindowLogRateLimiter();
}