#include "discountPricing.hpp"

DiscountPricing::DiscountPricing(Ride* ride): FareCalculator(ride) {

}

double DiscountPricing::calculateFare() {
    int basePrice = this->getBasePrice();
    return 0.8 * basePrice;
}