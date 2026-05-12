#include "rideManager.hpp"
#include "NearestMatching.hpp"
#include "thread"
#include "chrono"

int main() {
    RideManager* rideManager = RideManager::getInstance();
    rideManager->setRideMatchingStrategy(new NearestMatching());
    User* user = rideManager->addUser(1, "rithik");
    Driver* driver = rideManager->addDriver(2, "rahul");
    driver->setStatus(DRIVER_STATUS::ACTIVE);
    driver->setCurrentLocation(new Location(20, 20));
    Ride* ride = user->requestRide(new Location(0, 0), new Location(10, 10));
    Driver* assignedDriver = ride->getDriver();
    if (assignedDriver) {
       assignedDriver->startRide(ride);
       this_thread::sleep_for(chrono::seconds(5));
       assignedDriver->completeRide(ride);
    }
    user->showRideHistory();
    return 0;
}