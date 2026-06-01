#pragma once

#include "common.hpp"

class Screen;

class Seat
{
private:
    string id;
    Screen *screen;
    SEAT_CATEGORY category;
    SEAT_STATUS status;

public:
    Seat(string id, Screen *screen, SEAT_CATEGORY category);
    Seat(Seat* seat, Screen *screen);
    string getId();
    Screen *getScreen();
    SEAT_CATEGORY getCategory();
    SEAT_STATUS getStatus();
    void setStatus( SEAT_STATUS status);
    Seat* clone(Screen* screen);
};