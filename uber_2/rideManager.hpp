#pragma once

#include "common.hpp"
#include "mutex"
#include "location.hpp"
#include "rideMatching.hpp"

class User;
class Driver;
class Ride;

class RideManager {
    private:
        RideManager();
        static RideManager* instance;
        static mutex mtx;
        vector<User*> users;
        vector<Driver*> drivers;
        vector<Ride*> rides;
        RideMatching* rideMatchingStrategy;
    public:
        static RideManager* getInstance();
        void setRideMatchingStrategy(RideMatching* rideMatchingStrategy);
        User* addUser(int id, string name);
        Driver* addDriver(int id, string name);
        Ride* assignRide(User* user, Location* pickup, Location* drop);
        void setRideStatus(Ride* ride, RIDE_STATUS rideStatus);
};