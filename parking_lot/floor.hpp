#pragma once

#include "common.hpp"
#include "slot.hpp"

class Compare {
    public:
    bool operator()(Slot* a, Slot* b) {
        return a->getSlotNumber() > b->getSlotNumber();
    }
};

class Floor {
    private:
        unordered_map<VEHICLE_TYPE, priority_queue<Slot*, vector<Slot*>, Compare>> slots;
        int floorNumber;
        int slotNumber;  
    public:
        Floor(int floorNumber);
        void addSlot(VEHICLE_TYPE vehicleType);
        int getFloorNumber();
        unordered_map<VEHICLE_TYPE, priority_queue<Slot*, vector<Slot*>, Compare>>& getSlots();
};