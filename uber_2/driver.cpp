#include "driver.hpp"
#include "ride.hpp"
#include "rideManager.hpp"

Driver::Driver(int id, string name) : User(id, name)
{
}

void Driver::setStatus(DRIVER_STATUS status)
{
    this->status = status;
}

void Driver::setCurrentLocation(Location *currentLocation)
{
    this->currentLocation = currentLocation;
}

void Driver::handleRide(Ride *ride)
{
    // Depending on the ride, driver can accept/reject ride
    RideManager::getInstance()->setRideStatus(ride, RIDE_STATUS::ACCEPTED);
    this->status = DRIVER_STATUS::ACTIVE;
}

void Driver::startRide(Ride *ride)
{
    RideManager::getInstance()->setRideStatus(ride, RIDE_STATUS::IN_PROGRESS);
    this->status = DRIVER_STATUS::BUSY;
}

void Driver::completeRide(Ride *ride)
{
    RideManager::getInstance()->setRideStatus(ride, RIDE_STATUS::COMPLETED);
    this->status = DRIVER_STATUS::ACTIVE;
}

DRIVER_STATUS Driver::getDriverStatus()
{
    return this->status;
}

Location *Driver::getLocation()
{
    return this->currentLocation;
}