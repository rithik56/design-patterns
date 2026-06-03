#include "host.hpp"
#include "bookingManager.hpp"
#include "property.hpp"
#include "hostReview.hpp"
#include "booking.hpp"
#include "user.hpp"

Host::Host(int id, User *user)
{
    this->id = id;
    this->user = user;
}
int Host::getId()
{
    return this->id;
}
vector<Property *> Host::getProperties()
{
    return this->properties;
}
vector<HostReview *> Host::getReviews()
{
    return this->reviews;
}
vector<Booking *> Host::getBookings()
{
    return this->bookings;
}
void Host::acceptBooking(Booking *booking)
{
    BookingManager::getInstance()->updateBookingStatus(booking, BOOKING_STATUS::ACCEPTED);
}
void Host::rejectBooking(Booking *booking)
{
    BookingManager::getInstance()->updateBookingStatus(booking, BOOKING_STATUS::REJECTED);
}
void Host::addProperty(Property *property)
{
    this->properties.push_back(property);
}
void Host::removeProperty(Property *property)
{
}
void Host::showProperties()
{
    for (int i = 0; i < this->properties.size(); i++)
    {
        this->properties[i]->showDetails();
    }
}
void Host::showReviews()
{
    for (int i = 0; i < this->reviews.size(); i++)
    {
        this->reviews[i]->showReview();
    }
}
void Host::showBookings()
{
    for (int i = 0; i < this->bookings.size(); i++)
    {
        this->bookings[i]->showDetails();
    }
}

void Host::showDetails()
{
    cout << "Host Details: " << endl;
    this->user->showDetails();
}
void Host::addReview(HostReview *review)
{
    this->reviews.push_back(review);
}
void Host::addBooking(Booking *booking)
{
    this->bookings.push_back(booking);
}
User* Host::getUser() {
    return this->user;
}