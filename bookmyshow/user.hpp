#pragma once

#include "common.hpp"
#include "seat.hpp"
#include "show.hpp"
#include "location.hpp"

class Booking;

class User {
    private:
        int id;
        string name;
        string phone;
        Location* currentLocation;
        vector<Booking*> bookingHistory;
    public:
        User(int id, string name, string phone, Location* location);
        int getId();
        string getName();
        string getPhone();
        Location* getLocation();
        Booking* bookShow(Show* show, vector<Seat*> seats);
        void showBookingHistory();
        void addBooking(Booking* booking);
        void cancelBooking(Booking* booking);
};