#include "ride.hpp"
#include "rider.hpp"

Ride::Ride(string id, Rider* rider, Location* pickup, Location* drop) {
    this->id = id;
    this->rider = rider;
    this->pickup = pickup;
    this->drop = drop;
    this->rideStatus = RIDE_STATUS::NOT_ASSIGNED;
    this->driver = nullptr;
    this->payment = nullptr;
}

void Ride::setDriver(Driver* driver) {
    this->driver = driver;
}

void Ride::setRideStatus(RIDE_STATUS rideStatus) {
    this->rideStatus = rideStatus;
}

void Ride::setPayment(Payment* payment) {
    this->payment = payment;
}

string Ride::getRiderId() {
    return this->rider->getId();
}

string Ride::getDriverId() {
    return this->driver->getId();
}

RIDE_STATUS Ride::getRideStatus() {
    return this->rideStatus;
}

Driver* Ride::getDriver() {
    return this->driver;
}

Rider* Ride::getRider() {
    return this->rider;
}

Location* Ride::getPickupLocation() {
    return this->pickup;
}

Location* Ride::getDropLocation() {
    return this->drop;
}

string Ride::getRideId() {
    return this->id;
}

double Ride::getFare() {
    return this->payment->getAmount();
}

PAYMENT_STATUS Ride::getPaymentStatus() {
    return this->payment->getStatus();
}

double Ride::calculateFare() {
    Location* pickupLocation = this->pickup;
    Location* dropLocation = this->drop;

    int fareDistance = abs(pickupLocation->getLatitude() - dropLocation->getLatitude()) + abs(pickupLocation->getLongitude() - dropLocation->getLongitude());

    return fareDistance * 7.3;
}