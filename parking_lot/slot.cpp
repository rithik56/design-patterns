#include "slot.hpp"
#include "floor.hpp"

Slot::Slot(int slotNumber, VEHICLE_TYPE vehicleType, Floor* floor) {
    this->slotNumber = slotNumber;
    this->vehicleType = vehicleType;
    this->floor = floor;
}

int Slot::getSlotNumber() {
    return this->slotNumber;
}

VEHICLE_TYPE Slot::getVehicleType() {
    return this->vehicleType;
}

Floor* Slot::getFloor() {
    return this->floor;
}