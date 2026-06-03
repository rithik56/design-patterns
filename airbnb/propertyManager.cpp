#include "propertyManager.hpp"
#include "property.hpp"

PropertyManager* PropertyManager::instance = NULL;
mutex PropertyManager::mtx;

PropertyManager::PropertyManager() {

}

PropertyManager* PropertyManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new PropertyManager();
        }
        mtx.unlock();
    }
    return instance;
}

Property* PropertyManager::addProperty(string title, string description, int maxGuests, double price, PROPERTY_TYPE propertyType, PROPERTY_SUB_TYPE propertySubType, int numberOfRooms, int numberOfBathrooms, int numberOfBeds, vector<Amenities*> amenities, Host* host, Location* location, vector<Image*> images) {
    int propertyId = newPropertyId++;
    Property* property = new Property(propertyId, title, description, maxGuests, price, propertyType, propertySubType, numberOfRooms, numberOfBathrooms, numberOfBeds, amenities, host, location, images);
    this->mp[propertyId] = property; 
    return property;
}