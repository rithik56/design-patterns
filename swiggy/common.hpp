#pragma once

#include<iostream>
#include "unordered_set"
using namespace std;

enum ORDER_STATUS {
    NOT_ASSIGNED,
    ASSIGNED,
    STARTED,
    COMPLETED,
    CANCELLED
};

enum PAYMENT_STATUS {
    PENDING,
    IN_PROGRESS,
    PAYMENT_COMPLETED
};

extern int newItemId;
extern int newUserId;
extern int newOrderId;
extern int newRestaurantId;

extern const char* orderStatus[];
extern const char* paymentStatus[];