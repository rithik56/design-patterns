#pragma once

#include "common.hpp"
#include "movie.hpp"

class Theater;
class Seat;

class Screen {
    private:
        int id;
        Theater* theater;
        int rows;
        vector<vector<Seat*>> seats;
    public:
        Screen(int id, Theater* theater, int rows, int numberOfSeatsPerRow, unordered_map<int, pair<SEAT_CATEGORY, int>> customizedSeats);
        Screen(Screen* screen);
        int getId();
        Theater* getTheater();
        int getRows();   
        vector<vector<Seat*>> getSeats();
        Screen* clone();
        Seat* getSeatById(string seatId);
};