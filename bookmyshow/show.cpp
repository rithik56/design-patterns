#include "show.hpp"
#include "screen.hpp"
#include "booking.hpp"
#include "seat.hpp"

Show::Show(int id, Movie *movie, string startTiming, int duration, Screen *screen, unordered_map<SEAT_CATEGORY, int> seatPrice)
{
    this->id = id;
    this->movie = movie;
    this->startTiming = startTiming;
    this->duration = duration;
    this->screen = screen;
    this->seatPrice = seatPrice;
}
int Show::getId()
{
    return this->id;
}
Movie *Show::getMovie()
{
    return this->movie;
}
string Show::getStartTiming()
{
    return this->startTiming;
}
int Show::getDuration()
{
    return this->duration;
}
Screen *Show::getScreen()
{
    return this->screen;
}
unordered_map<SEAT_CATEGORY, int>& Show::getSeatPrice()
{
    return this->seatPrice;
}

void Show::showSeats() {
    for (int i = 0; i < this->screen->getSeats().size(); i++) {
        cout << (i + 1) << " row" << endl;
        cout << this->screen->getSeats()[i].size() << endl;
        for (int j = 0; j < this->screen->getSeats()[i].size(); j++) {
            cout << "seat number: " << this->screen->getSeats()[i][j]->getId() << " " << "seat status: " << displaySeatStatus[this->screen->getSeats()[i][j]->getStatus()] << " " << "seat cost: " << this->seatPrice[this->screen->getSeats()[i][j]->getCategory()] << endl;
        }
    }
    cout << endl;
}

void Show::addBooking(Booking* booking) {
    this->bookings[booking->getId()] = booking;
}

Seat* Show::getSeatById(string seatId) {
    return this->screen->getSeatById(seatId);
}