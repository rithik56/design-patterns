#include "parkingManager.hpp"

mutex ParkingManager::mtx;
ParkingManager *ParkingManager::parkingManager = nullptr;

ParkingManager::ParkingManager() {}

ParkingManager *ParkingManager::getParkingManagerInstance()
{
    if (parkingManager == nullptr)
    {
        mtx.lock();
        if (parkingManager == nullptr)
        {
            parkingManager = new ParkingManager();
        }
        mtx.unlock();
    }
    return parkingManager;
}

Floor* ParkingManager::addFloor() {
    int floorNumber = this->floors.size();
    Floor* floor = new Floor(floorNumber);
    this->floors.push_back(floor);
    return floor;
}

void ParkingManager::assignTicket(Vehicle *vehicle)
{
    VEHICLE_TYPE vehicleType = vehicle->getVehicleType();
    for (int i = 0; i < this->floors.size(); i++)
    {
        if (this->floors[i]->getSlots()[vehicleType].size() == 0)
        {
            continue;
        }
        Slot *freeSlot = this->floors[i]->getSlots()[vehicleType].top();
        this->floors[i]->getSlots()[vehicleType].pop();
        Ticket *ticket = new Ticket(ticketNumber++, freeSlot, vehicle);
        this->tickets[vehicle->getVehicleNumber()].push_back(ticket);
        return;
    }
    cout << "Sorry, Parking is full" << endl;
}

void ParkingManager::showAvailableSlotsPerFloor()
{
    for (int i = 0; i < this->floors.size(); i++)
    {
        cout << i << " Floor available slots" << endl;
        for (auto it = this->floors[i]->getSlots().begin(); it != this->floors[i]->getSlots().end(); it++) {

            if (it->second.size() == 0) {
                cout << "no available slots for " << vehicleType[it->first] << endl;
                continue;
            }

            cout << vehicleType[it->first] << " available slots: " << it->second.size() << endl;
        }
    }
}

void ParkingManager::handleExit(Vehicle *vehicle) {
    Ticket* ticket = this->tickets[vehicle->getVehicleNumber()][this->tickets[vehicle->getVehicleNumber()].size() - 1];
    
    time_t result = time(nullptr);

    ticket->exitTimestamp = result;

    int hoursPassed = calculateHours(ticket->entryTimestamp, ticket->exitTimestamp);

    ticket->parkingFee = parkingFeeMap[vehicle->getVehicleType()] * hoursPassed;

    this->floors[ticket->getSlot()->getFloor()->getFloorNumber()]->getSlots()[ticket->getSlot()->getVehicleType()].push(ticket->getSlot());
}

vector<Ticket*>& ParkingManager::getVehicleTickets(int vehicleNumber) {
    return this->tickets[vehicleNumber];
}

