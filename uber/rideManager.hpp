#pragma once
#include "common.hpp"
#include "unordered_map"
#include "rider.hpp"
#include "driver.hpp"
#include "ride.hpp"
#include "mutex"

class RideManager {
    private:
        RideManager();
        static RideManager* rideManagerInstance;
        static mutex mtx;
        static unordered_map<string, Rider*> riders;
        static unordered_map<string, Driver*> drivers;
        static unordered_map<string, Ride*> rides;
    public:
        static RideManager* getRideManagerInstance();
        static void addRider(Rider* rider);
        static void addDriver(Driver* driver);
        static void assignRide(Ride* ride);
        static void cancelRide(string riderId, RIDE_STATUS rideStatus);
        static void acceptRide(string driverId);
        static void rejectRide(string driverId);
        static void startRide(string rideId);
        static void completeRide(string rideId);
        static string getRiderTripId(string rideId, RIDE_STATUS rideStatus);
        static string getDriverTripId(string driverId, RIDE_STATUS rideStatus);
};