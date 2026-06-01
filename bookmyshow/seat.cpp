#include "seat.hpp"

Seat::Seat(string id, Screen *screen, SEAT_CATEGORY category)
{
    this->id = id;
    this->screen = screen;
    this->category = category;
    this->status = SEAT_STATUS::AVAILABLE;
};

Seat::Seat(Seat* seat, Screen* screen) {
    this->id = seat->id;
    this->screen = seat->screen;
    this->category = seat->category;
    this->status = seat->status;
}

string Seat::getId()
{
    return this->id;
}
Screen *Seat::getScreen()
{
    return this->screen;
}
SEAT_CATEGORY Seat::getCategory()
{
    return this->category;
}
SEAT_STATUS Seat::getStatus()
{
    return this->status;
}

void Seat::setStatus(SEAT_STATUS status)
{
    this->status = status;
}

Seat* Seat::clone(Screen* screen) {
    return new Seat(this, screen);
}