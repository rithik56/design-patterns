#pragma once

#include "rideMatching.hpp"

class NearestMatching: public RideMatching {
    public:
        Driver* assignRide(Ride* ride, vector<Driver*> drivers);
};