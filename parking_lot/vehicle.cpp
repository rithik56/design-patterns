#include "vehicle.hpp"
#include "parkingManager.hpp"

Vehicle::Vehicle(int vehicleNumber, VEHICLE_TYPE vehicleType) {
    this->vehicleNumber = vehicleNumber;
    this->vehicleType = vehicleType;
}

void Vehicle::enterParking() {
    ParkingManager::getParkingManagerInstance()->assignTicket(this);
}

void Vehicle::exitParking() {
    ParkingManager::getParkingManagerInstance()->handleExit(this);
}

int Vehicle::getVehicleNumber() {
    return this->vehicleNumber;
}

VEHICLE_TYPE Vehicle::getVehicleType() {
    return this->vehicleType;
}