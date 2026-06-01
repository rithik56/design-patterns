#include "screen.hpp"
#include "theater.hpp"
#include "seat.hpp"

Screen::Screen(int id, Theater *theater, int rows, int numberOfSeatsPerRow, unordered_map<int, pair<SEAT_CATEGORY, int>> customizedSeats)
{
    this->id = id;
    this->theater = theater;
    this->rows = rows;
    vector<vector<Seat*>> seats;
    for (int i = 0; i < rows; i++) {
        vector<Seat*> row;
        SEAT_CATEGORY seatCategory = customizedSeats.find(i) == customizedSeats.end() ? SEAT_CATEGORY::NORMAL : customizedSeats[i].first;
        int numberOfSeats = customizedSeats.find(i) == customizedSeats.end() ? numberOfSeatsPerRow : customizedSeats[i].second;
        for (int j = 0; j < numberOfSeats; j++) {
            row.push_back(new Seat(to_string(i) + " " + to_string(j), this, seatCategory));
        }
        seats.push_back(row);
    }
    this->seats = seats;
}

Screen::Screen(Screen* screen) {
    this->id = screen->id;
    this->theater = screen->theater;
    this->rows = screen->rows;
    vector<vector<Seat*>> seats;
    for (int i = 0; i < screen->getSeats().size(); i++) {
        vector<Seat*> row;
        for (int j = 0; j < screen->getSeats()[i].size(); j++) {
            row.push_back(screen->getSeats()[i][j]->clone(this));
        }
        seats.push_back(row);
    }
    this->seats = seats;
}

int Screen::getId()
{
    return this->id;
}
Theater *Screen::getTheater()
{
    return this->theater;
}
int Screen::getRows()
{
    return this->rows;
}

vector<vector<Seat*>> Screen::getSeats() {
    return this->seats;
}

Screen* Screen::clone() {
    return new Screen(this);
}

Seat* Screen::getSeatById(string seatId) {
    vector<string> strings;
    string currString = "";
    for (int i = 0; i < seatId.size(); i++) {
        if (seatId[i] == ' ') {
            strings.push_back(currString);
            currString = "";
        } else {
            currString += seatId[i];
        }
    }
    strings.push_back(currString);
    int rowNumber = stoi(strings[0]);
    int seatNumber = stoi(strings[1]);
    return this->seats[rowNumber][seatNumber];
}