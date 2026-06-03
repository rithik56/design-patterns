#pragma once

#include "common.hpp"
#include "unordered_set"

class PropertyReview;
class Host;
class Booking;
class Amenities;
class Location;
class Image;

class Property {
    private:
        int id;
        string title;
        string description;
        vector<PropertyReview*> reviews;
        int maxGuests;
        double price;
        unordered_set<string> availabilityCalender;
        PROPERTY_TYPE propertyType;
        PROPERTY_SUB_TYPE propertySubType;
        int numberOfRooms;
        int numberOfBathrooms;
        int numberOfBeds;
        vector<Amenities*> amenities;
        Host* host;
        vector<Booking*> bookings;
        Location* location;
        vector<Image*> images;
    public:
        Property(int id, string title, string description, int maxGuests, double price, PROPERTY_TYPE propertyType, PROPERTY_SUB_TYPE propertySubType, int numberOfRooms, int numberOfBathrooms, int numberOfBeds, vector<Amenities*> amenities, Host* host, Location* location, vector<Image*> images);
        int getId();
        string getTitle();
        string getDescription();
        vector<PropertyReview*> getReviews();
        int getMaxGuests();
        double getPrice();
        unordered_set<string>& getAvalibilityCalender();
        PROPERTY_TYPE getPropertyType();
        PROPERTY_SUB_TYPE getPropertySubType();
        int getNumberOfRooms();
        int getNumberOfBathrooms();
        int getNumberOfBeds();
        vector<Amenities*>& getAmenities();
        Host* getHost();
        vector<Booking*>& getBookings();
        Location* getLocation();
        vector<Image*>& getImages();
        void setTitle(string title);
        void setDescription(string description);
        void addReview(PropertyReview* review);
        void removeReview(PropertyReview* review);
        void setMaxGuests(int maxGuests);
        void setPrice(double price);
        void openData(string date);
        void closeData(string date);
        void setPropertyType(PROPERTY_TYPE type);
        void setPropertySubType(PROPERTY_SUB_TYPE subType);
        void setNumberOfRooms(int numberOfRooms);
        void setNumberOfBathrooms(int numberOfBathrooms);
        void setNumberOfBeds(int numberOfBeds);
        void addAmenity(Amenities* amenity);
        void removeAmenity(Amenities* amenity);
        void addBooking(Booking* booking);
        void setLocation(Location* location);
        void addImage(Image* image);
        void removeImage(Image* image);
        void showDetails();
        double calculatePrice(string startDate, string endDate);
        void showPrice(string startDate, string endDate);
};