#pragma once

#include "common.hpp"
#include "mutex"

class Booking;
class Property;
class Host;
class User;
class Payment;

class BookingManager {
    private:
        BookingManager();
        static BookingManager* instance;
        static mutex mtx;
        unordered_map<int, Booking*> mp;
    public:
        static BookingManager* getInstance();
        Booking* createBooking(User* guest, Property* property, int numberOfGuests, string startDate, string endDate);
        void updateBookingStatus(Booking* booking, BOOKING_STATUS status);
};