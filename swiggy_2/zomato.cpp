#include "orderManager.hpp"
#include "user.hpp"
#include "partnerMatchingStrategy.hpp"

int main()
{
    OrderManager *orderManager = OrderManager::getInstance();
    orderManager->setPartnerMatchingStrategy(new PartnerMatchingStrategy());
    User *user = orderManager->addUser(newUserId++, "Rithik");
    DeliveryPartner *deliveryPartner = orderManager->addDeliveryPartner(newDeliveryPartnerId++, "Rahul");
    deliveryPartner->setCurrentLocation(new Location(5, 5));
    deliveryPartner->setStatus(DRIVER_STATUS::ACTIVE);
    Restaurant *restaurant = orderManager->addRestaurant(newRestaurantId++, "Haldiram", new Location(10, 10));
    Item *item1 = restaurant->addItem("Chole Bhature", 220.0);
    Item *item2 = restaurant->addItem("Dosa", 160.0);
    user->addItem(item1, restaurant);
    user->addItem(item1, restaurant);
    user->addItem(item2, restaurant);
    Order *order = user->placeOrder();
    DeliveryPartner *assignedPartner = order->getDeliveryPartner();
    if (assignedPartner)
    {
        assignedPartner->startDelivery(order);
        assignedPartner->completeDelivery(order);
    }
    // Restaurant Name: Haldiram
    // Items:
    // Item Name: Chole Bhature
    // Item Price: 220
    // Quantity: 2
    // Item Name: Dosa
    // Item Price: 160
    // Quantity: 1
    // Total Amount: 600
    // Order Status: COMPLETED
    // Payment Status: PENDING
    user->showOrderHistory();
    return 0;
}