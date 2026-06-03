#include "user.hpp"
#include "hostManager.hpp"
#include "guestReview.hpp"
#include "bookingManager.hpp"
#include "propertyReviewManager.hpp"
#include "hostReviewManager.hpp"
#include "guestReviewManager.hpp"
#include "booking.hpp"
#include "property.hpp"

User::User(int id, string name, string phone)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->host = HostManager::getInstance()->createHost(this);
}
int User::getId()
{
    return this->id;
}
string User::getName()
{
    return this->name;
}
string User::getPhone()
{
    return this->phone;
}
Host *User::getHost()
{
    return this->host;
}
vector<Booking *> &User::getBookings()
{
    return this->bookings;
}
vector<GuestReview *> &User::getGuestReviews()
{
    return this->reviews;
}
void User::showDetails()
{
    cout << "Name: " << this->name << endl;
}
Booking *User::bookProperty(Property *property, int numberOfGuest, string startDate, string endDate)
{
    Booking *booking = BookingManager::getInstance()->createBooking(this, property, numberOfGuest, startDate, endDate);
    return booking;
}
void User::reviewHost(Booking *booking, Rating *rating)
{
    HostReview *review = HostReviewManager::getInstance()->createHostReview(booking->getProperty()->getHost(), this, rating);
}
void User::reviewProperty(Booking *booking, Rating *rating)
{
    PropertyReview *review = PropertyReviewManager::getInstance()->createPropertyReview(booking->getProperty(), this, rating);
}
void User::reviewGuest(Booking *booking, Rating *rating)
{
    GuestReview *review = GuestReviewManager::getInstance()->createGuestReview(booking->getProperty()->getHost(), this, rating);
}
void User::addBooking(Booking *booking)
{
    this->bookings.push_back(booking);
}
void User::addReview(GuestReview *review)
{
    this->reviews.push_back(review);
}
void User::checkIn(Booking *booking)
{
    BookingManager::getInstance()->updateBookingStatus(booking, BOOKING_STATUS::CHECK_IN);
}
void User::checkOut(Booking *booking)
{
    BookingManager::getInstance()->updateBookingStatus(booking, BOOKING_STATUS::CHECK_OUT);
}
void User::showBookings() {
    for (int i = 0; i < this->bookings.size(); i++) {
        this->bookings[i]->showDetails();
    }
}