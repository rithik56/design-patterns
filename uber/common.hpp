#pragma once

#include<iostream>
using namespace std;

enum RIDE_STATUS {
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

static string newRideId = "1234";
static string newUserId = "1234";

