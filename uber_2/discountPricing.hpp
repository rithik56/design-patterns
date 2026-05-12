#pragma once

#include "common.hpp"
#include "fareCalculator.hpp"
#include "ride.hpp"

class DiscountPricing: public FareCalculator {
    public:
        DiscountPricing(Ride* ride);
        double calculateFare() override;
};