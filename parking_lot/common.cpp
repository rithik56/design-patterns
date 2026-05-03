#include "common.hpp"
#include "unordered_map"
#include<ctime>

int vehicleNumber = 1;
int ticketNumber = 1;

const char* vehicleType[] = {
    "BIKE",
    "CAR",
    "TRUCK"
};

const char* paymentStatus[] = {
    "PENDING",
    "IN_PROGRESS",
    "PAYMENT_COMPLETED"
};

unordered_map<VEHICLE_TYPE, int> parkingFeeMap = {
    {BIKE, 20},
    {CAR, 40},
    {TRUCK, 60}
};

int calculateHours(time_t entryTime, time_t exitTime) {
    double secondsPassed = difftime(exitTime, entryTime);
    double hoursPassed = secondsPassed / 3600.0;
    return ceil(hoursPassed);
}