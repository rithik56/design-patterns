#include "user.hpp"
#include "rideManager.hpp"
#include "ride.hpp"

User::User(int id, string name) {
    this->id = id;
    this->name = name;
}

Ride* User::requestRide(Location* pickup, Location* drop) {
    return RideManager::getInstance()->assignRide(this, pickup, drop);
}

void User::showRideHistory() {
    for (int i = 0; i < this->rideHistory.size(); i++) {
        cout << "User Name: " << this->name << endl;
        cout << "Driver Name: " << this->rideHistory[i]->getDriver()->getName() << endl;
        cout << "Pickup Location: " << this->rideHistory[i]->getPick()->getLocation().first << " " << this->rideHistory[i]->getPick()->getLocation().second << endl;
        cout << "Drop Location: " << this->rideHistory[i]->getDrop()->getLocation().first << " " << this->rideHistory[i]->getDrop()->getLocation().second << endl;
        cout << "Start Time: " << chrono::duration_cast<chrono::seconds>(
    this->rideHistory[i]->getStartTime().time_since_epoch()
).count() << endl;
        cout << "End Time: " << chrono::duration_cast<chrono::seconds>(
    this->rideHistory[i]->getEndTime().time_since_epoch()
).count() << endl;
        cout << "Fare: " << this->rideHistory[i]->getPayment()->getAmount() << endl;
        cout << "Ride Status: " << rideStatus[this->rideHistory[i]->getRideStatus()] << endl;
        cout << "Payment Status: " << paymentStatus[this->rideHistory[i]->getPayment()->getPaymentStatus()] << endl;
        cout << endl;
    }
}

string User::getName() {
    return this->name;
}

void User::addRideToHistory(Ride* ride) {
    this->rideHistory.push_back(ride);
}