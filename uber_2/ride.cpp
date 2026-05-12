#include "ride.hpp"


Ride::Ride(User *user, Location *pick, Location *drop)
{
    this->user = user;
    this->pick = pick;
    this->drop = drop;
}

void Ride::setRideStatus(RIDE_STATUS status)
{
    this->status = status;
}

int Ride::calculateFare()
{
    return this->fareCalculator->calculateFare();
}

void Ride::processPayment()
{ 
    this->payment->processPayment();
}

User *Ride::getUser()
{
    return this->user;
}
Driver *Ride::getDriver()
{
    return this->driver;
}
Location *Ride::getPick()
{
    return this->pick;
}
Location *Ride::getDrop()
{
    return this->drop;
}
RIDE_STATUS Ride::getRideStatus()
{
    return this->status;
}
Payment *Ride::getPayment()
{
    return this->payment;
}
chrono::steady_clock::time_point Ride::getStartTime()
{
    return this->startTime;
}
chrono::steady_clock::time_point Ride::getEndTime()
{
    return this->endTime;
}

void Ride::setDriver(Driver* driver) {
    this->driver = driver;
}

void Ride::setFareCalculator(FareCalculator* fareCalculator) {
    this->fareCalculator = fareCalculator;
}

void Ride::setPayment(Payment* payment) {
    this->payment = payment;
}

        void Ride::setStartTime(chrono::steady_clock::time_point startTime) {
            this->startTime = startTime;
        }
        void Ride::setEndTime(chrono::steady_clock::time_point endTime) {
            this->endTime = endTime;
        }