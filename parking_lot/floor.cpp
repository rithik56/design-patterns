#include "floor.hpp"
#include "slot.hpp"


Floor::Floor(int floorNumber) {
    this->floorNumber = floorNumber;
    this->slotNumber = 1;
}

void Floor::addSlot(VEHICLE_TYPE vehicleType) {
    this->slots[vehicleType].push(new Slot(this->slotNumber, vehicleType, this));
    this->slotNumber++;
}

unordered_map<VEHICLE_TYPE, priority_queue<Slot*, vector<Slot*>, Compare>>& Floor::getSlots() {
    return this->slots;
}

int Floor::getFloorNumber() {
    return this->floorNumber;
}