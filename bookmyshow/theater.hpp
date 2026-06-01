#pragma once

#include "common.hpp"
#include "location.hpp"
#include "movie.hpp"

class Screen;
class Show;

class Theater {
    private:
        int id;
        string name;
        Location* location;
        vector<Screen*> screens;
        unordered_map<Movie*, int> movies;
        unordered_map<int, vector<Show*>> schedule;
    public:
        Theater(int id, string name, Location* location);
        void addScreen(int rows, int numberOfSeatsPerRow, unordered_map<int, pair<SEAT_CATEGORY, int>> customizedSeats);
        void displayMovieTimings(Movie* movie, string data);
        void displayShowTimings(string data);
        Show* addShow(Movie *movie, string date, string startTiming, int duration, int screenId, unordered_map<SEAT_CATEGORY, int> seatPrice);
        Screen* getFreshScreen(int screenId);
        Location* getLocation();
        string getName();
        int getId();
};  