#include "bookingManager.hpp"
#include "show.hpp"
#include "user.hpp"
#include "screen.hpp"

int main()
{
    BookingManager *bookingManager = BookingManager::getInstance();
    Theater *theater1 = bookingManager->addTheater("Cinepolis NSP", new Location(10, 10));
    Theater *theater2 = bookingManager->addTheater("PVR Prashant Vihar", new Location(2, 2));
    unordered_map<int, pair<SEAT_CATEGORY, int>> customizedSeats = {
        {19, make_pair(SEAT_CATEGORY::VIP, 10)},
    };
    theater1->addScreen(20, 15, customizedSeats);
    theater2->addScreen(20, 15, customizedSeats);
    theater1->addScreen(20, 15, customizedSeats);
    theater2->addScreen(20, 15, customizedSeats);
    Movie *movie1 = new Movie(movieId++, 180, "3 Idiots", "Hindi");
    Movie *movie2 = new Movie(movieId++, 180, "Avatar", "English");
    unordered_map<SEAT_CATEGORY, int> show1Price = {
        {SEAT_CATEGORY::NORMAL, 400},
        {SEAT_CATEGORY::PREMIUM, 550},
        {SEAT_CATEGORY::VIP, 700},
    };
    unordered_map<SEAT_CATEGORY, int> show2Price = {
        {SEAT_CATEGORY::NORMAL, 240},
        {SEAT_CATEGORY::PREMIUM, 450},
        {SEAT_CATEGORY::VIP, 500},
    };
    unordered_map<SEAT_CATEGORY, int> show3Price = {
        {SEAT_CATEGORY::NORMAL, 350},
        {SEAT_CATEGORY::PREMIUM, 500},
        {SEAT_CATEGORY::VIP, 650},
    };
    unordered_map<SEAT_CATEGORY, int> show4Price = {
        {SEAT_CATEGORY::NORMAL, 200},
        {SEAT_CATEGORY::PREMIUM, 300},
        {SEAT_CATEGORY::VIP, 400},
    };

    Show *show1 = theater1->addShow(movie1, "20/05/2026", "10:00 AM", 195, 0, show1Price);
    Show *show2 = theater2->addShow(movie2, "20/05/2026", "03:00 PM", 180, 0, show2Price);
    Show *show3 = theater1->addShow(movie1, "21/05/2026", "03:00 PM", 200, 1, show3Price);
    Show *show4 = theater2->addShow(movie2, "22/05/2026", "10:00 AM", 195, 1, show4Price);

//     Movie 3 Idiots:
// 03:00 PM 10:00 AM 
    theater1->displayShowTimings("20/05/2026");

    User *user1 = new User(userId++, "Rithik", "9643093218", new Location(0, 0));
    User *user2 = new User(userId++, "Rahul", "8643093218", new Location(9, 9));

//     PVR Prashant Vihar
// Movie 3 Idiots:

// Cinepolis NSP
// Movie 3 Idiots:
// 03:00 PM 10:00 AM
    bookingManager->displayMovieShows(movie1, "22/05/2026", user1->getLocation());

    // show1->showSeats();

    Seat *seat1 = show1->getSeatById("0 5");
    Seat *seat2 = show1->getSeatById("10 5");
    Seat *seat3 = show1->getSeatById("19 5");

    Booking *user1Booking = user1->bookShow(show1, {seat1, seat2, seat3});

    // show1->showSeats();

    user1Booking->getPayment()->processPayment();

    // show2->showSeats();

    Seat *seat4 = show2->getSeatById("7 4");

    Booking *user2Booking = user2->bookShow(show4, {seat4});

    // show2->showSeats();

    //     Movie Title: 3 Idiots
    // Movie Duration: 180
    // Movie Language: Hindi
    // Seats:
    // 0 5 NORMAL
    // 10 5 NORMAL
    // 19 5 VIP
    // Total Price: 1500
    // Payment Status: SUCCESSFUL
    // Booking Status: SUCCESS
    user1->showBookingHistory();

    //     Movie Title: Avatar
    // Movie Duration: 180
    // Movie Language: English
    // Seats:
    // 7 4 NORMAL
    // Total Price: 200
    // Payment Status: PENDING
    // Booking Status: SUCCESS
    user2->showBookingHistory();

    return 0;
}