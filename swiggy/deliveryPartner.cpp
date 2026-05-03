#include "deliveryPartner.hpp"

DeliveryPartner::DeliveryPartner(int id, string name, string phone) : User(id, name, phone) {
    this->currentLocation = nullptr;
    this->isAvailable = false;
}

void DeliveryPartner::updateAvailability(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void DeliveryPartner::updateCurrentLocation(Location* currentLocation) {
    this->currentLocation = currentLocation;
}

bool DeliveryPartner::getIsAvailable() {
    return this->isAvailable;
}

Location* DeliveryPartner::getCurrentLocation() {
    return this->currentLocation;
}