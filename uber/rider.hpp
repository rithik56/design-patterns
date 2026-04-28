#pragma once

#include "common.hpp"
#include "user.hpp"
#include "location.hpp"

class Ride;

class Rider: public User {
    private:
        vector<Ride*> rideHistory;
    public:
        Rider(string id, string name, string phone);
        Ride* requestRide(Location* pickup, Location* drop);
        void cancelRide(RIDE_STATUS rideStatus);
        void showRideHistory();
};