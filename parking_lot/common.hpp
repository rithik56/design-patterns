#pragma once

#include <iostream>
using namespace std;

enum VEHICLE_TYPE {
    BIKE,
    CAR,
    TRUCK
};

enum PAYMENT_STATUS {
    PENDING,
    IN_PROGRESS,
    PAYMENT_COMPLETED
};

enum PAYMENT_MODE {
    CASH,
    UPI,
    CARD
};

extern int vehicleNumber;
extern int ticketNumber;

extern unordered_map<VEHICLE_TYPE, int> parkingFeeMap;

extern int calculateHours(time_t entryTime, time_t exitTime);

extern const char* vehicleType[];
extern const char* paymentStatus[];