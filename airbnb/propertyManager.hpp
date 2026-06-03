#pragma once

#include "common.hpp"
#include "mutex"

class Property;
class Amenities;
class Host;
class Image;
class Location;

class PropertyManager {
    private:
        PropertyManager();
        static PropertyManager* instance;
        static mutex mtx;
        unordered_map<int, Property*> mp;
    public:
        static PropertyManager* getInstance();
        Property* addProperty(string title, string description, int maxGuests, double price, PROPERTY_TYPE propertyType, PROPERTY_SUB_TYPE propertySubType, int numberOfRooms, int numberOfBathrooms, int numberOfBeds, vector<Amenities*> amenities, Host* host, Location* location, vector<Image*> images);
};