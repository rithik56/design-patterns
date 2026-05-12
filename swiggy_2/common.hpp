#pragma once

#include<iostream>

using namespace std;

class Location;

enum DRIVER_STATUS {
    ACTIVE,
    BUSY,
    INACTIVE
};

enum PAYMENT_STATUS {
    PENDING,
   PROCESSING,
    SUCCESSFUL
};

enum ORDER_STATUS {
    ACCEPTED,
    REJECTED,
    NOT_ASSIGNED,
    ASSIGNED,
    IN_PROGRESS,
    COMPLETED,
    CANCELLED
};

extern const char* driverStatus[];
extern const char* paymentStatus[];
extern const char* orderStatus[];

int calculateDistance(Location* a, Location* b);

extern int newUserId;
extern int newDeliveryPartnerId;
extern int newRestaurantId;
extern int newOrderId;