#include "common.hpp"
#include "rateLimitConfig.hpp"

const char* userType[] = {
    "FREE",
    "PREMIUM"
};

double TOKEN_BUCKET_REFILL_RATE_FACTOR = 0.5;
double LEAKY_BUCKET_OUTFLOW_RATE_FACTOR = 0.5;

int newUserId = 1;
int newQuestionId = 1;

unordered_map<USER_TYPE, RateLimitConfig*> rateLimitMap = {
    {FREE, new RateLimitConfig(2, 10)},
    {PREMIUM, new RateLimitConfig(5, 10)}
};