#include "rideManager.hpp"
#include "user.hpp"
#include "driver.hpp"
#include "ride.hpp"
#include "discountPricing.hpp"

RideManager::RideManager() {

}

RideManager* RideManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new RideManager();
        }
        mtx.unlock();
    }
    return instance;
}

RideManager* RideManager::instance = nullptr;
mutex RideManager::mtx;

User* RideManager::addUser(int id, string name) {
    User* user = new User(id, name);
    this->users.push_back(user);
    return user;
}

Driver* RideManager::addDriver(int id, string name) {
    Driver* driver = new Driver(id, name);
    this->drivers.push_back(driver);
    return driver;
}

Ride* RideManager::assignRide(User* user, Location* pickup, Location* drop) {
    Ride* ride = new Ride(user, pickup, drop);
    ride->setDriver(this->rideMatchingStrategy->assignRide(ride, this->drivers));
    return ride;
}

void RideManager::setRideStatus(Ride* ride, RIDE_STATUS rideStatus) {
    if (rideStatus == RIDE_STATUS::COMPLETED) {
        ride->setEndTime(chrono::steady_clock::now());
        ride->setFareCalculator(new DiscountPricing(ride));
        int fare = ride->calculateFare();
        ride->setPayment(new Payment(fare));
    } else if (rideStatus == RIDE_STATUS::ASSIGNED) {
        ride->getUser()->addRideToHistory(ride);
    } else if (rideStatus == RIDE_STATUS::IN_PROGRESS) {
        ride->setStartTime(chrono::steady_clock::now());
    }
    ride->setRideStatus(rideStatus);
}

void RideManager::setRideMatchingStrategy(RideMatching* rideMatchingStrategy) {
    this->rideMatchingStrategy = rideMatchingStrategy;
}