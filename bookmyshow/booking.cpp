#include "booking.hpp"
#include "user.hpp"
#include "show.hpp"

Booking::Booking(int id, User *user, Show *show, vector<Seat *> seats, Payment *payment)
{
    this->id = id;
    this->user = user;
    this->show = show;
    this->seats = seats;
    this->payment = payment;
    this->status = BOOKING_STATUS::SUCCESS;
}
int Booking::getId()
{
    return this->id;
}
User *Booking::getUser()
{
    return this->user;
}
Show *Booking::getShow()
{
    return this->show;
}
vector<Seat *> Booking::getSeats()
{
    return this->seats;
}
Payment *Booking::getPayment()
{
    return this->payment;
}

BOOKING_STATUS Booking::getStatus()
{
    return this->status;
}

void Booking::setStatus(BOOKING_STATUS bookingStatus)
{
    this->status = bookingStatus;
}