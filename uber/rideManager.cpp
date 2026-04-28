#include "rideManager.hpp"

RideManager* RideManager::rideManagerInstance = nullptr;
mutex RideManager::mtx;

unordered_map<string, Rider*> RideManager::riders;
unordered_map<string, Driver*> RideManager::drivers;
unordered_map<string, Ride*> RideManager::rides;

RideManager::RideManager() {

}

RideManager* RideManager::getRideManagerInstance() {
    if (rideManagerInstance == nullptr) {
        mtx.lock();
        if (rideManagerInstance == nullptr) {
            rideManagerInstance = new RideManager();
        }
        mtx.unlock();
    }
    return rideManagerInstance;
}

void RideManager::addRider(Rider* rider) {
    string riderId = rider->getId();
    rideManagerInstance->riders[riderId] = rider;
}

void RideManager::addDriver(Driver* driver) {
    string driverId = driver->getId();
    rideManagerInstance->drivers[driverId] = driver;
}

string RideManager::getRiderTripId(string riderId, RIDE_STATUS rideStatus) {
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if ((it->second)->getDriverId() == riderId && (it->second)->getRideStatus() == rideStatus) {
            return it->first;
        }
    }
    return "";
}

string RideManager::getDriverTripId(string driverId, RIDE_STATUS rideStatus) {
    for (auto it = rides.begin(); it != rides.end(); it++) {
        if ((it->second)->getDriverId() == driverId && (it->second)->getRideStatus() == rideStatus) {
            return it->first;
        }
    }
    return "";
}

void RideManager::cancelRide(string riderId, RIDE_STATUS rideStatus) {
    string rideId = getRiderTripId(riderId, rideStatus);
    rideManagerInstance->rides[rideId]->setRideStatus(RIDE_STATUS::CANCELLED);
}

void RideManager::acceptRide(string driverId) {
    string rideId = getDriverTripId(driverId, RIDE_STATUS::ASSIGNED);
    rideManagerInstance->rides[rideId]->setRideStatus(RIDE_STATUS::ASSIGNED);
}

void RideManager::rejectRide(string driverId) {
    string rideId = getDriverTripId(driverId, RIDE_STATUS::NOT_ASSIGNED);
    rideManagerInstance->rides[rideId]->setRideStatus(RIDE_STATUS::CANCELLED);
}

void RideManager::startRide(string rideId) {
    rideManagerInstance->rides[rideId]->setRideStatus(RIDE_STATUS::STARTED);
}

void RideManager::completeRide(string rideId) {
    rideManagerInstance->rides[rideId]->setRideStatus(RIDE_STATUS::COMPLETED);
}

void RideManager::assignRide(Ride* ride) {

    string rideId = ride->getRideId();

    rideManagerInstance->rides[rideId] = ride;

    Location* pickupLocation = ride->getPickupLocation();
    if (drivers.size() == 0) {
        cout << "no drivers available at the moment" << endl;
        return;
    }

    Driver* nearestDriver;
    int minDistance = INT_MAX;

    for (auto it = drivers.begin(); it != drivers.end(); it++) {
        Location* driverLocation = it->second->getCurrentLocation();
        int currDistance = abs(pickupLocation->getLatitude() - driverLocation->getLatitude()) + abs(pickupLocation->getLongitude() - driverLocation->getLongitude());
        if (currDistance < minDistance) {
            minDistance = currDistance;
            nearestDriver = it->second;
        }
    }

    Location* dropLocation = ride->getDropLocation();

    int fareDistance = abs(pickupLocation->getLatitude() - dropLocation->getLatitude()) + abs(pickupLocation->getLongitude() - dropLocation->getLongitude());

    ride->setDriver(nearestDriver);
    ride->setPayment(new Payment(fareDistance * 7.3));
    ride->setRideStatus(RIDE_STATUS::ASSIGNED);
}



