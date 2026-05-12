#include "fareCalculator.hpp"
#include "ride.hpp"


FareCalculator::FareCalculator(Ride* ride) {
    this->ride = ride;
}

int FareCalculator::getDistance() {
    Location* pick = this->ride->getPick();
    Location* drop = this->ride->getDrop();
    return calculateDistance(pick, drop);
}

int FareCalculator::getTime() {
    chrono::steady_clock::time_point startTime = this->ride->getStartTime();
    chrono::steady_clock::time_point endTime = this->ride->getEndTime();
    int duration = chrono::duration_cast<
        chrono::seconds
    >(endTime - startTime).count();
    return duration;
}

double FareCalculator::getBasePrice() {
    int distance = this->getDistance();
    int duration = this->getTime();
    return (distance * 7) + duration;
}