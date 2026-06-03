#pragma once

#include "common.hpp"

class PropertyReview;
class Booking;
class Host;
class GuestReview;
class Property;
class Rating;

class User {
    private:
        int id;
        string name;
        string phone;
        Host* host;
        vector<Booking*> bookings;
        vector<GuestReview*> reviews;
    public:
        User(int id, string name, string phone);
        int getId();
        string getName();
        string getPhone();
        Host* getHost();
        Booking* bookProperty(Property* property, int numberOfGuest, string startDate, string endDate);
        vector<Booking*>& getBookings();
        vector<GuestReview*>& getGuestReviews();
        void showDetails();
        void addBooking(Booking* booking);
        void addReview(GuestReview* review);
        void reviewHost(Booking* booking, Rating* rating);
        void reviewProperty(Booking* booking, Rating* rating);
        void reviewGuest(Booking* booking, Rating* rating);
        void checkIn(Booking* booking);
        void checkOut(Booking* booking);
        void showBookings();
};