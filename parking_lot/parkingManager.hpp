#pragma once

#include "floor.hpp"
#include "ticket.hpp"
#include "vehicle.hpp"
#include "mutex"
#include "common.hpp"

class ParkingManager {
    private:
        ParkingManager();
        static ParkingManager* parkingManager;
        static mutex mtx;
        vector<Floor*> floors;
        unordered_map<int, vector<Ticket*>> tickets;
    public:
        static ParkingManager* getParkingManagerInstance();
        Floor* addFloor();
        void assignTicket(Vehicle* vehicle);
        void showAvailableSlotsPerFloor();
        void handleExit(Vehicle *vehicle);
        vector<Ticket*>& getVehicleTickets(int vehicleNumber);
};