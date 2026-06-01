#pragma once

#include "common.hpp"
#include "mutex"
#include "theater.hpp"
#include "movie.hpp"
#include "booking.hpp"
#include "seat.hpp"

class User;
class Show;

class BookingManager {
    private:
        BookingManager();
        static mutex mtx;
        static BookingManager* instance;
        vector<Theater*> theaters;
    public:
        static BookingManager* getInstance();
        Theater* addTheater(string name, Location* location);
        void displayMovieShows(Movie* movie, string date, Location* location);
        Booking* bookTickets(User* user, Show* show, vector<Seat*> seats);
        void cancelBooking(Booking* booking);
};