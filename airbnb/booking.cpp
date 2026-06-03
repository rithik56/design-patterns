#include "booking.hpp"
#include "chat.hpp"
#include "property.hpp"
#include "user.hpp"
#include "payment.hpp"
#include "host.hpp"

Booking::Booking(int id, User *guest, Property *property, Payment *payment, int numberOfGuests, string startDate, string endDate)
{
    this->id = id;
    this->guest = guest;
    this->property = property;
    this->payment = payment;
    this->numberOfGuests = numberOfGuests;
    this->startDate = startDate;
    this->endDate = endDate;
    this->status = BOOKING_STATUS::PENDING;
}
void Booking::setBookingStatus(BOOKING_STATUS status)
{
    this->status = status;
}
int Booking::getId()
{
    return this->id;
}
User *Booking::getGuest()
{
    return this->guest;
}
Property *Booking::getProperty()
{
    return this->property;
}
Payment *Booking::getPayment()
{
    return this->payment;
}
BOOKING_STATUS Booking::getBookingStatus()
{
    return this->status;
}
int Booking::getNumberOfGuests()
{
    return this->numberOfGuests;
}
Chat *Booking::getChat()
{
    return this->chat;
}
string Booking::getStartDate()
{
    return this->startDate;
}
string Booking::getEndDate()
{
    return this->endDate;
}
void Booking::showDetails()
{
    cout << "Booking Details: " << endl;
    cout << "Property Title: " << this->property->getTitle() << endl;
    cout << "Number of Guests: " << this->numberOfGuests << endl;
    cout << "Start Date: " << this->startDate << endl;
    cout << "End Date: " << this->endDate << endl;
    cout << "Guest Name: " << this->guest->getName() << endl;
    cout << "Host Name: " << this->property->getHost()->getUser()->getName() << endl;
    this->payment->showPaymentDetails();
    cout << "Booking status: " << this->status << endl;
}