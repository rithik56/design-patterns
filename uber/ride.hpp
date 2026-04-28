#pragma once
#include "common.hpp"
#include "driver.hpp"
#include "payment.hpp"

class Rider;

class Ride {
    private:
        string id;
        Rider* rider;
        Driver* driver;
        Payment* payment;
        Location* pickup;
        Location* drop;
        RIDE_STATUS rideStatus;
    public:
        Ride(string id, Rider* rider, Location* pickup, Location* drop);
        void setDriver(Driver* driver);
        void setPayment(Payment* payment);
        void setRideStatus(RIDE_STATUS rideStatus);
        string getRiderId();
        string getDriverId();
        RIDE_STATUS getRideStatus();
        Driver* getDriver();
        Rider* getRider();
        Location* getPickupLocation();
        Location* getDropLocation();
        string getRideId();
        double getFare();
        PAYMENT_STATUS getPaymentStatus();
};