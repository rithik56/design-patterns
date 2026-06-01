#pragma once

#include "common.hpp"
#include "seat.hpp"
#include "payment.hpp"

class User;
class Show;

class Booking {
    private:
        int id;
        User* user;
        Show* show;
        vector<Seat*> seats;
        Payment* payment;
        BOOKING_STATUS status;
    public:
        Booking(int id, User* user, Show* show, vector<Seat*> seats, Payment* payment);
        int getId();
        User* getUser();
        Show* getShow();
        vector<Seat*> getSeats();
        Payment* getPayment();
        BOOKING_STATUS getStatus();
        void setStatus(BOOKING_STATUS bookingStatus);
};