#include "common.hpp"
#include "location.hpp"

const char* paymentStatus[] = {
    "PENDING",
    "PROCESSING",
    "COMPLETED"
};

const char* rideStatus[] = {
    "NOT_ASSIGNED",
    "ACCEPTED",
    "ASSIGNED",
    "IN_PROGRESS",
    "COMPLETED",
    "CANCELLED"  
};

const char* driverStatus[] = {
    "ACTIVE",
    "INACTIVE",
    "BUSY"
};

int calculateDistance(Location* pick, Location* drop) {
    pair<int, int> p1 = pick->getLocation();
    pair<int, int> p2 = drop->getLocation();
    return abs(p1.first - p2.first) + abs(p2.first - p2.second);
}