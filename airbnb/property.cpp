#include "property.hpp"
#include "amenities.hpp"
#include "image.hpp"
#include "location.hpp"
#include "host.hpp"
#include "propertyReview.hpp"

Property::Property(int id, string title, string description, int maxGuests, double price, PROPERTY_TYPE propertyType, PROPERTY_SUB_TYPE propertySubType, int numberOfRooms, int numberOfBathrooms, int numberOfBeds, vector<Amenities *> amenities, Host *host, Location *location, vector<Image *> images)
{
    this->id = id;
    this->title = title;
    this->description = description;
    this->maxGuests = maxGuests;
    this->price = price;
    this->propertyType = propertyType;
    this->propertySubType = propertySubType;
    this->numberOfRooms = numberOfRooms;
    this->numberOfBathrooms = numberOfBathrooms;
    this->numberOfBeds = numberOfBeds;
    this->amenities = amenities;
    this->host = host;
    this->location = location;
    this->images = images;
}
int Property::getId()
{
    return this->id;
}
string Property::getTitle()
{
    return this->title;
}
string Property::getDescription()
{
    return this->description;
}
vector<PropertyReview *> Property::getReviews()
{
    return this->reviews;
}
int Property::getMaxGuests()
{
    return this->maxGuests;
}
double Property::getPrice()
{
    return this->price;
}
unordered_set<string> &Property::getAvalibilityCalender()
{
    return this->availabilityCalender;
}
PROPERTY_TYPE Property::getPropertyType()
{
    return this->propertyType;
}
PROPERTY_SUB_TYPE Property::getPropertySubType()
{
    return this->propertySubType;
}
int Property::getNumberOfRooms()
{
    return this->numberOfRooms;
}
int Property::getNumberOfBathrooms()
{
    return this->numberOfBathrooms;
}
int Property::getNumberOfBeds()
{
    return this->numberOfBeds;
}
vector<Amenities *> &Property::getAmenities()
{
    return this->amenities;
}
Host *Property::getHost()
{
    return this->host;
}
vector<Booking *> &Property::getBookings()
{
    return this->bookings;
}
Location *Property::getLocation()
{
    return this->location;
}
vector<Image *> &Property::getImages()
{
    return this->images;
}
void Property::setTitle(string title)
{
    this->title = title;
}
void Property::setDescription(string description)
{
    this->description = description;
}
void Property::addReview(PropertyReview *review)
{
    this->reviews.push_back(review);
}
void Property::removeReview(PropertyReview *review)
{
}
void Property::setMaxGuests(int maxGuests)
{
    this->maxGuests = maxGuests;
}
void Property::setPrice(double price)
{
    this->price = price;
}
void Property::openData(string date)
{
    this->availabilityCalender.insert(date);
}
void Property::closeData(string date)
{
    this->availabilityCalender.erase(date);
}
void Property::setPropertyType(PROPERTY_TYPE type)
{
    this->propertyType = type;
}
void Property::setPropertySubType(PROPERTY_SUB_TYPE subType)
{
    this->propertySubType = subType;
}
void Property::setNumberOfRooms(int numberOfRooms)
{
    this->numberOfRooms = numberOfRooms;
}
void Property::setNumberOfBathrooms(int numberOfBathrooms)
{
    this->numberOfBathrooms = numberOfBathrooms;
}
void Property::setNumberOfBeds(int numberOfBeds)
{
    this->numberOfBeds = numberOfBeds;
}
void Property::addAmenity(Amenities *amenity)
{
    this->amenities.push_back(amenity);
}
void Property::removeAmenity(Amenities *amenity)
{
}
void Property::addBooking(Booking *booking)
{
    this->bookings.push_back(booking);
}
void Property::setLocation(Location *location)
{
    this->location = location;
}
void Property::addImage(Image *image)
{
    this->images.push_back(image);
}
void Property::removeImage(Image *image)
{
}
void Property::showDetails()
{
    cout << "Property Details: " << endl;
    for (int i = 0; i < this->images.size(); i++)
    {
        this->images[i]->showImage();
    }
    this->location->showDetails();
    cout << "Title: " << this->title << endl;
    cout << "Description: " << this->description << endl;
    cout << "Property Type: " << this->propertyType << endl;
    cout << "Property Sub Type: " << this->propertySubType << endl;
    cout << "Number of Rooms: " << this->numberOfRooms << endl;
    cout << "Number of Bathrooms: " << this->numberOfBathrooms << endl;
    cout << "Number of Beds: " << this->numberOfBeds << endl;
    cout << "Max Guests: " << this->maxGuests << endl;
    for (int i = 0; i < this->amenities.size(); i++)
    {
        this->amenities[i]->show();
    }
    this->host->showDetails();
    cout << "Reviews: " << endl;
    for (int i = 0; i < this->reviews.size(); i++)
    {
        this->reviews[i]->showReview();
    }
}
double Property::calculatePrice(string startDate, string endDate) {
    return this->price;
}
void Property::showPrice(string startDate, string endDate) {
    double price = this->calculatePrice(startDate, endDate);
    cout << "Price Quotation: " << price << endl;
}