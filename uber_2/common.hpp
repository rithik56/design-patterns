#pragma once

#include<iostream>
using namespace std;

class Location;

enum PAYMENT_STATUS {
    PENDING,
    PROCESSING,
    PAYMENT_COMPLETED
};

enum RIDE_STATUS {
    NOT_ASSIGNED,
    ACCEPTED,
    ASSIGNED,
    IN_PROGRESS,
    COMPLETED,
    CANCELLED   
};

enum DRIVER_STATUS {
    ACTIVE,
    INACTIVE,
    BUSY
};

int calculateDistance(Location* pick, Location* drop);

extern const char* paymentStatus[];
extern const char* rideStatus[];
extern const char* driverStatus[];