#pragma once

#include "common.hpp"
#include "ride.hpp"
#include "driver.hpp"

class RideMatching {
    public:
        virtual Driver* assignRide(Ride* ride, vector<Driver*> drivers) = 0;
};