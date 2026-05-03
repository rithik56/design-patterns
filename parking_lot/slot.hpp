#pragma once

#include "common.hpp"

class Floor;

class Slot {
    private:
        int slotNumber;
        VEHICLE_TYPE vehicleType;
        Floor* floor;
    public:
        Slot(int slotNumber, VEHICLE_TYPE vehicleType, Floor* floor);
        int getSlotNumber();
        VEHICLE_TYPE getVehicleType();
        Floor* getFloor();
};