#pragma once

#include "common.hpp"

class Vehicle {
    private:
        int vehicleNumber;
        VEHICLE_TYPE vehicleType;
    public:
        Vehicle(int vehicleNumber, VEHICLE_TYPE vehicleType);
        void enterParking();
        void exitParking();
        int getVehicleNumber();
        VEHICLE_TYPE getVehicleType();
};