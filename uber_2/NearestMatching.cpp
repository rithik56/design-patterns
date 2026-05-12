#include "NearestMatching.hpp"
#include "ride.hpp"
#include "driver.hpp"
#include "rideManager.hpp"

Driver* NearestMatching::assignRide(Ride* ride, vector<Driver*> drivers) {
    Location* pick = ride->getPick();
    int minDistance = INT_MAX;
    Driver* driver = nullptr;

    for (int i = 0; i < drivers.size(); i++) {
        if (drivers[i]->getDriverStatus() == DRIVER_STATUS::ACTIVE) {
            int distance = calculateDistance(pick, drivers[i]->getLocation());
            if (distance < minDistance) {
                minDistance = distance;
                driver = drivers[i];
            }
        }
    }
    if (driver == nullptr) {
        cout << "sorry no driver available at the moment" << endl;
    }

    RideManager::getInstance()->setRideStatus(ride, RIDE_STATUS::ASSIGNED);

    return driver;
}