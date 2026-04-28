#pragma once

#include "common.hpp"
#include "user.hpp"
#include "location.hpp"

class Driver: public User {
    private:
        bool isAvailable;
        Location* currentLocation;
    public:
        Driver(string id, string name, string phone, bool isAvailable, Location* currentLocation);
        void acceptRide();
        void rejectRide();
        void updateAvailability(bool isAvailable);
        void updateCurrentLocation(Location* currentLocation);
        bool getIsAvailable();
        Location* getCurrentLocation();
};