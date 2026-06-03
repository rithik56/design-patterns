#include "userManager.hpp"
#include "propertyManager.hpp"
#include "location.hpp"
#include "amenities.hpp"
#include "user.hpp"
#include "host.hpp"
#include "amenities.hpp"
#include "image.hpp"
#include "rating.hpp"
#include "property.hpp"

int main() {
    UserManager* userManager = UserManager::getInstance();
    PropertyManager* propertyManager = PropertyManager::getInstance();
    User* user1 = userManager->addUser("rithik", "9876543210");
    User* user2 = userManager->addUser("rahul", "9212432433");
    Property* property1 = propertyManager->addProperty("Rithik's Villa", "A home away from home", 4, 2100.0, PROPERTY_TYPE::FLAT, PROPERTY_SUB_TYPE::ENTIRE_UNIT, 2, 2, 2, {new Amenities("Wifi Enabled", "wifi icon")}, user1->getHost(), new Location(10, 10), {new Image("image1.jpg")});
    user1->getHost()->addProperty(property1);
    property1->openData("03/06/2026");
    property1->openData("04/06/2026");
    Booking* booking = user2->bookProperty(property1, 3, "03/06/2026", "04/06/2026");
    user1->getHost()->acceptBooking(booking);
    user2->checkIn(booking);
    user2->checkOut(booking);
    user2->reviewHost(booking, new Rating(5.0, "Rithik was a great host"));
    user2->reviewProperty(booking, new Rating(5.0, "Rithik's property was great. Would love to visit again."));
    user1->reviewGuest(booking, new Rating(5.0, "Rahul was a great guest"));
    User* user3 = userManager->addUser("amol", "9212432433");
    user3->bookProperty(property1, 4, "04/06/2026", "05/06/2026");
    user3->checkIn(booking);
    user3->checkOut(booking);
    user3->reviewProperty(booking, new Rating(4.5, "Rithik's property was great but Wifi wasn't working great"));
    user2->showBookings();
    property1->showDetails();
    return 0;
}