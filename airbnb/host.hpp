#pragma once

#include "common.hpp"

class User;
class Property;
class HostReview;
class Booking;

class Host {
    private:
        int id;
        User* user;
        vector<Property*> properties;
        vector<HostReview*> reviews;
        vector<Booking*> bookings;
    public:
        Host(int id, User* user);
        int getId();
        vector<Property*> getProperties();
        vector<HostReview*> getReviews();
        vector<Booking*> getBookings();
        void acceptBooking(Booking* booking);
        void rejectBooking(Booking* booking);
        void addProperty(Property* property);
        void removeProperty(Property* property);
        void showProperties();
        void showReviews();
        void showBookings();
        void showDetails();
        void addReview(HostReview* review);
        void addBooking(Booking* booking);
        User* getUser();
};
