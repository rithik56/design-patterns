#pragma once

#include "common.hpp"
#include "user.hpp"
#include "location.hpp"

class DeliveryPartner: public User {
    private:
        Location* currentLocation;
        bool isAvailable;
    public:
        DeliveryPartner(int id, string name, string phone);
        void updateAvailability(bool isAvailable);
        void updateCurrentLocation(Location* currentLocation);
        bool getIsAvailable();
        Location* getCurrentLocation();
};