#pragma once

#include "common.hpp"
#include "location.hpp"

class Order;

class DeliveryPartner {
    private:
        int id;
        string name;
        DRIVER_STATUS status;
        Location* currentLocation;
    public: 
        DeliveryPartner(int id, string name);
        string getName();
        int getId();
        void startDelivery(Order* order);
        void completeDelivery(Order* order);
        void setStatus(DRIVER_STATUS status);
        void setCurrentLocation(Location* currentLocation);
        DRIVER_STATUS getStatus();
        Location* getCurrentLocation();
};