#include "rider.hpp"
#include "rideManager.hpp"
#include "ride.hpp"

Rider::Rider(string id, string name, string phone): User(id, name, phone) {

}

Ride* Rider::requestRide(Location* pickup, Location* drop) {
    Ride* ride = new Ride(newRideId, this, pickup, drop);
    newRideId = "1235";
    RideManager::assignRide(ride);
    this->rideHistory.push_back(ride);
    return ride;
}

void Rider::cancelRide(RIDE_STATUS rideStatus) {
    RideManager::cancelRide(this->id, rideStatus);
}

void Rider::showRideHistory() {
    cout << "ride History of rider " + this->getName() << endl;
    for (int i = 0; i < this->rideHistory.size(); i++) {
        cout << "Pickup Location " << this->rideHistory[i]->getPickupLocation()->getLatitude() << " " <<  this->rideHistory[i]->getPickupLocation()->getLongitude() << endl;
        cout << "Drop Location " << this->rideHistory[i]->getDropLocation()->getLatitude() << " " <<  this->rideHistory[i]->getDropLocation()->getLongitude() << endl;
        cout << "Driver " << this->rideHistory[i]->getDriver()->getName() << endl;
        cout << "Fare " << this->rideHistory[i]->getFare() << endl;
        cout << "Payment Status " << this->rideHistory[i]->getPaymentStatus() << endl;
        cout << endl;
    }
}