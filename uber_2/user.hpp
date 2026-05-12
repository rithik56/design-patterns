#pragma once

#include "common.hpp"
#include "location.hpp"

class Ride;
class RideManager;

class User {
    protected:
        int id;
        string name;
        vector<Ride*> rideHistory;
    public:
        User(int id, string name);
        Ride* requestRide(Location* pickup, Location* drop);
        void showRideHistory();
        string getName();
        void addRideToHistory(Ride* ride);
};