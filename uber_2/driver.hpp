#pragma once

#include "common.hpp"
#include "user.hpp"

class Ride;

class Driver: public User {
    private:
        DRIVER_STATUS status;
        Location* currentLocation;
    public:
        Driver(int id, string name);
        void setStatus(DRIVER_STATUS status);
        void setCurrentLocation(Location* currentLocation);
        void handleRide(Ride* ride);
        void startRide(Ride* ride);
        void completeRide(Ride* ride);
        DRIVER_STATUS getDriverStatus();
        Location* getLocation();
};