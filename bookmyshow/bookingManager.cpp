#include "bookingManager.hpp"
#include "user.hpp"
#include "show.hpp"

mutex BookingManager::mtx;
BookingManager *BookingManager::instance = nullptr;

BookingManager::BookingManager()
{
}

BookingManager* BookingManager::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new BookingManager();
        }
        mtx.unlock();
    }
    return instance;
}

Theater *BookingManager::addTheater(string name, Location *location)
{
    int id = this->theaters.size();
    Theater *theater = new Theater(id, name, location);
    this->theaters.push_back(theater);
    return theater;
}

void BookingManager::displayMovieShows(Movie *movie, string date, Location *location)
{
    sort(this->theaters.begin(), this->theaters.end(), [location](Theater* a, Theater* b) {
        int dist1 = abs(a->getLocation()->getLocation().first - location->getLocation().first) +  abs(a->getLocation()->getLocation().second - location->getLocation().second);
        int dist2 = abs(b->getLocation()->getLocation().first - location->getLocation().first) +  abs(b->getLocation()->getLocation().second - location->getLocation().second);
        return dist1 < dist2;
    });
    for (int i = 0; i < this->theaters.size(); i++) {
        cout << this->theaters[i]->getName() << endl;
        this->theaters[i]->displayMovieTimings(movie, date);
    }
}

Booking *BookingManager::bookTickets(User *user, Show *show, vector<Seat*> seats)
{
    int cost = 0;
    for (int i = 0; i < seats.size(); i++) {
        cost += show->getSeatPrice()[seats[i]->getCategory()];
        seats[i]->setStatus(SEAT_STATUS::BOOKED);
    }
    Payment* payment = new Payment(cost);
    Booking* booking = new Booking(bookingId++, user, show, seats, payment);
    show->addBooking(booking);
    user->addBooking(booking);
    return booking;
}

void BookingManager::cancelBooking(Booking* booking)
{
    for (int i = 0; i < booking->getSeats().size(); i++) {
        booking->getSeats()[i]->setStatus(SEAT_STATUS::AVAILABLE);
    }
    booking->setStatus(BOOKING_STATUS::CANCELLED);
}

