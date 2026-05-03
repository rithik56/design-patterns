#include "common.hpp"

int newItemId = 1;
int newUserId = 1;
int newOrderId = 1;
int newRestaurantId = 1;

const char* orderStatus[] = {
    "NOT_ASSIGNED",
    "ASSIGNED",
    "STARTED",
    "COMPLETED",
    "CANCELLED"
};

const char* paymentStatus[] = {
    "PENDING",
    "IN_PROGRESS",
    "PAYMENT_COMPLETED"
};