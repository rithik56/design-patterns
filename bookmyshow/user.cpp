#include "user.hpp"
#include "booking.hpp"
#include "bookingManager.hpp"
#include "screen.hpp"

User::User(int id, string name, string phone, Location* location)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->currentLocation = location;
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
Booking *User::bookShow(Show *show, vector<Seat *> seats)
{
    Booking* booking = BookingManager::getInstance()->bookTickets(this, show, seats);
    return booking;
}
void User::showBookingHistory()
{
    for (int i = 0; i < this->bookingHistory.size(); i++) {
        cout << "Movie Title: " << this->bookingHistory[i]->getShow()->getMovie()->getTitle() << endl;
        cout << "Movie Duration: " << bookingHistory[i]->getShow()->getMovie()->getDuration() << endl;
        cout << "Movie Language: " << bookingHistory[i]->getShow()->getMovie()->getLanguage() << endl;
        cout << "Theater Name: " << bookingHistory[i]->getShow()->getScreen()->getTheater()->getName() << endl;
        cout << "Theater Id: " << bookingHistory[i]->getShow()->getScreen()->getTheater()->getId() << endl;
        cout << "Seats: " << endl;
        for (int j = 0; j < bookingHistory[i]->getSeats().size(); j++) {
            cout << bookingHistory[i]->getSeats()[j]->getId() << " " << displaySeatCategory[bookingHistory[i]->getSeats()[j]->getCategory()] << endl;
        }
        cout << "Total Price: " << bookingHistory[i]->getPayment()->getAmount() << endl;
        cout << "Payment Status: " << displayPaymentStatus[bookingHistory[i]->getPayment()->getPaymentStatus()] << endl;
        cout << "Booking Status: " << displayBookingStatus[bookingHistory[i]->getStatus()] << endl << endl;
    }
}

void User::addBooking(Booking* booking) {
    this->bookingHistory.push_back(booking);
}

void User::cancelBooking(Booking* booking)
{
    BookingManager::getInstance()->cancelBooking(booking);
}

Location* User::getLocation() {
    return this->currentLocation;
}