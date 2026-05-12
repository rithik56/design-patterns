#pragma once

#include "common.hpp"

class Ride;

class FareCalculator {
    private:
        Ride* ride;
    public:
        FareCalculator(Ride* ride);
        virtual double calculateFare() = 0;
        int getDistance();
        int getTime();
        double getBasePrice();
};