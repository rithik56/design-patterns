#include "common.hpp"
#include "location.hpp"

const char* driverStatus[] = {
    "ACTIVE",
    "BUSY",
    "INACTIVE"
};

const char* paymentStatus[] = {
    "PENDING",
   "PROCESSING",
    "SUCCESSFUL"
};

const char* orderStatus[] = {
    "ACCEPTED",
    "REJECTED",
    "NOT_ASSIGNED",
    "ASSIGNED",
    "IN_PROGRESS",
    "COMPLETED",
    "CANCELLED"
};

int calculateDistance(Location* a, Location* b) {
    pair<int, int> src = a->getLocation();
    pair<int, int> dest = b->getLocation();
    return abs(src.first - dest.first) + abs(src.second - dest.second);
};

int newUserId = 1;
int newDeliveryPartnerId = 1;
int newRestaurantId = 1;
int newOrderId = 1;