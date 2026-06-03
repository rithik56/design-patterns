#pragma once

#include "common.hpp"

class User;
class Chat;
class Property;
class Payment;

class Booking {
    private:
        int id;
        User* guest;
        Property* property;
        Payment* payment;
        BOOKING_STATUS status;
        int numberOfGuests;
        Chat* chat;
        string startDate;
        string endDate;
    public:
        Booking(int id, User* guest, Property* property, Payment* payment, int numberOfGuests, string startDate, string endDate);
        void setBookingStatus(BOOKING_STATUS status);
        int getId();
        User* getGuest();
        Property* getProperty();
        Payment* getPayment();
        BOOKING_STATUS getBookingStatus();
        int getNumberOfGuests();
        Chat* getChat();
        string getStartDate();
        string getEndDate();
        void showDetails();
};
