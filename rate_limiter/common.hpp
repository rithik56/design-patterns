#pragma once

#include<iostream>

using namespace std;

class RateLimitConfig;

enum USER_TYPE {
    FREE,
    PREMIUM
};

extern double TOKEN_BUCKET_REFILL_RATE_FACTOR;
extern double LEAKY_BUCKET_OUTFLOW_RATE_FACTOR;

extern int newUserId;
extern int newQuestionId;

extern unordered_map<USER_TYPE, RateLimitConfig*> rateLimitMap;