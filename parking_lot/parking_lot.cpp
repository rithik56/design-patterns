#include "parkingManager.hpp"

int main()
{
    ParkingManager *parkingManager = ParkingManager::getParkingManagerInstance();
    Floor *groundFloor = parkingManager->addFloor();
    Floor *firstFloor = parkingManager->addFloor();
    for (int i = 0; i < 1; i++)
    {
        groundFloor->addSlot(BIKE);
        groundFloor->addSlot(CAR);
        groundFloor->addSlot(TRUCK);

        firstFloor->addSlot(BIKE);
        firstFloor->addSlot(CAR);
        firstFloor->addSlot(TRUCK);
    }
    Vehicle *bike1 = new Vehicle(vehicleNumber++, BIKE);
    Vehicle *bike2 = new Vehicle(vehicleNumber++, BIKE);
    Vehicle *bike3 = new Vehicle(vehicleNumber++, BIKE);
    Vehicle *car1 = new Vehicle(vehicleNumber++, CAR);
    Vehicle *car2 = new Vehicle(vehicleNumber++, CAR);
    Vehicle *car3 = new Vehicle(vehicleNumber++, CAR);
    Vehicle *truck1 = new Vehicle(vehicleNumber++, TRUCK);
    Vehicle *truck2 = new Vehicle(vehicleNumber++, TRUCK);
    Vehicle *truck3 = new Vehicle(vehicleNumber++, TRUCK);

    bike1->enterParking();
    
    bike2->enterParking();

    car1->enterParking();
    truck1->enterParking();

    // Sorry, Parking is full
    bike3->enterParking();

    // 0 Floor available slots
    // no available slots for TRUCK
    // no available slots for CAR
    // no available slots for BIKE
    // 1 Floor available slots
    // TRUCK available slots: 1
    // CAR available slots: 1
    // no available slots for BIKE
    parkingManager->showAvailableSlotsPerFloor();

    bike1->exitParking();
    car1->exitParking();

    // 0 Floor available slots
    // no available slots for TRUCK
    // CAR available slots: 1
    // BIKE available slots: 1
    // 1 Floor available slots
    // TRUCK available slots: 1
    // CAR available slots: 1
    // no available slots for BIKE
    parkingManager->showAvailableSlotsPerFloor();

    bike3->enterParking();

    vector<Ticket *> bike1Tickets = parkingManager->getVehicleTickets(bike1->getVehicleNumber());

    // payment done by the UPI
    bike1Tickets[bike1Tickets.size() - 1]->processPayment(UPI);

    vector<Ticket *> car1Tickets = parkingManager->getVehicleTickets(car1->getVehicleNumber());

    // payment done by the cash
    car1Tickets[car1Tickets.size() - 1]->processPayment(CASH);

    return 0;
}