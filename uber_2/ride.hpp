#pragma once

#include "common.hpp"
#include "chrono"
#include "fareCalculator.hpp"
#include "location.hpp"
#include "driver.hpp"
#include "user.hpp"
#include "payment.hpp"

class Ride {
    private:
        User* user;
        Location* pick;
        Location* drop;
        chrono::steady_clock::time_point startTime;
        chrono::steady_clock::time_point endTime;
        Driver* driver;
        RIDE_STATUS status;
        Payment* payment;
        FareCalculator* fareCalculator;
    public:
        Ride(User* user, Location* pick, Location* drop);
        void setRideStatus(RIDE_STATUS status);
        void setFareCalculator(FareCalculator* fareCalculator);
        int calculateFare();
        void processPayment();
        User* getUser();
        Driver* getDriver();
        Location* getPick();
        Location* getDrop();
        RIDE_STATUS getRideStatus();
        Payment* getPayment();
        chrono::steady_clock::time_point getStartTime();
        chrono::steady_clock::time_point getEndTime();
        void setDriver(Driver* driver);
        void setPayment(Payment* payment);
        void setStartTime(chrono::steady_clock::time_point startTime);
        void setEndTime(chrono::steady_clock::time_point endTime);
};