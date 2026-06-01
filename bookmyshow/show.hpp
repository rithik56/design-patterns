#pragma once

#include "common.hpp"
#include "movie.hpp"

class Screen;
class Booking;
class Seat;

class Show {
    private:
        int id;
        Movie* movie;
        string startTiming;
        int duration;
        Screen* screen;
        unordered_map<int, Booking*> bookings;
        unordered_map<SEAT_CATEGORY, int> seatPrice;
    public:
        Show(int id, Movie* movie, string startTiming, int duration, Screen* screen, unordered_map<SEAT_CATEGORY, int> seatPrice);
        int getId();
        Movie* getMovie();
        string getStartTiming();
        int getDuration();
        Screen* getScreen();
        unordered_map<SEAT_CATEGORY, int>& getSeatPrice();
        void showSeats();
        void addBooking(Booking* booking);
        Seat* getSeatById(string seatId);
};