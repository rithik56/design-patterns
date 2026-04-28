#include "rideManager.hpp"

int main()
{
    Rider *rider = new Rider(newUserId, "rithik", "9643093318");
    newUserId = "1235";
    Driver *driver = new Driver(newUserId, "rahul", "9826666630", true, new Location(0, 0));
    newUserId = "1236";
    RideManager *rideManager = RideManager::getRideManagerInstance();
    rideManager->addRider(rider);
    rideManager->addDriver(driver);
    Ride *ride = rider->requestRide(new Location(5, 9), new Location(9, 1));
    ride->getDriver()->acceptRide();
    rideManager->startRide(ride->getRideId());
    rideManager->completeRide(ride->getRideId());
    // ride History of rider rithik
    // Pickup Location 5 9
    // Drop Location 9 1
    // Driver rahul
    // Fare 87.6
    // Payment Status 0
    rider->showRideHistory();
    return 0;
}