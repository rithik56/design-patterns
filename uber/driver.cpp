#include "driver.hpp"
#include "rideManager.hpp"

Driver::Driver(string id, string name, string phone, bool isAvailable, Location* currentLocation): User(id, name, phone) {
    this->isAvailable = isAvailable;
    this->currentLocation = currentLocation;
}

void Driver::acceptRide() {
    RideManager::acceptRide(this->id);
}

void Driver::rejectRide() {
    RideManager::rejectRide(this->id);
}

void Driver::updateAvailability(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void Driver::updateCurrentLocation(Location* currentLocation) {
    this->currentLocation = currentLocation;
}

bool Driver::getIsAvailable() {
    return this->isAvailable;
}

Location* Driver::getCurrentLocation() {
    return this->currentLocation;
}

