#include "orderManager.hpp"
#include "item.hpp"
#include "cart.hpp"

int main()
{
    OrderManager *orderManager = OrderManager::getOrderManagerInstance();
    User *user = orderManager->addUser("rithik", "9643013319");
    DeliveryPartner *deliveryPartner = orderManager->addDeliveryPartner("rahul", "9643093318");
    deliveryPartner->updateCurrentLocation(new Location(8, 8));
    deliveryPartner->updateAvailability(true);
    Restaurant *restaurant = orderManager->addRestaurant("Dominos", new Location(2, 2));
    restaurant->addItem("Farmhouse Pizza", 500.0, "onion, tomato and capsicum pizza");
    restaurant->addItem("Cheeseburst Pizza", 300.0, "onion, tomato and capsicum pizza");
    Restaurant *restaurant2 = orderManager->addRestaurant("Haldiram", new Location(6, 6));
    restaurant2->addItem("Chole Bhature", 200.0, "delicious and fulfulling dish");
    restaurant2->addItem("Pao Bhaji", 200.0, "delicious pav bhaji");
    DeliveryPartner *deliveryPartner2 = orderManager->addDeliveryPartner("ajay", "8643093318");
    deliveryPartner2->updateCurrentLocation(new Location(4, 4));
    deliveryPartner2->updateAvailability(true);
    Restaurant *restaurant3 = orderManager->addRestaurant("Bikaner", new Location(20, 20));
    restaurant3->addItem("Dal Makhani", 400.0, "delicious north indian dish");
    for (auto it = restaurant->getItems().begin(); it != restaurant->getItems().end(); it++)
    {
        if (it->second->getName() == "Farmhouse Pizza")
        {
            user->getCart()->addItem(it->second);
        }
    }
    for (auto it = restaurant2->getItems().begin(); it != restaurant2->getItems().end(); it++)
    {
        if (it->second->getName() == "Pao Bhaji")
        {
            user->getCart()->addItem(it->second);
        }
    }
    for (auto it = restaurant3->getItems().begin(); it != restaurant3->getItems().end(); it++)
    {
        if (it->second->getName() == "Dal Makhani")
        {
            user->getCart()->addItem(it->second);
        }
    }
    user->updateCommunicationAddress(new Location(18, 16));
    user->placeOrder();
    orderManager->startDelivery(deliveryPartner->getId());
    orderManager->startDelivery(deliveryPartner2->getId());
    orderManager->completeDelivery(deliveryPartner->getId());
    orderManager->completeDelivery(deliveryPartner2->getId());
    user->showOrderHistory();
    // Order History
    // Restaurant Name: Dominos
    // Items:
    // Farmhouse Pizza 1
    // Order Cost: 722
    // Order Status: COMPLETED
    // Payment Status: PENDING

    // Restaurant Name: Bikaner
    // Items:
    // Dal Makhani 1
    // Order Cost: 444.4
    // Order Status: CANCELLED
    // Payment Status: PENDING

    // Restaurant Name: Haldiram
    // Items:
    // Pao Bhaji 1
    // Order Cost: 362.8
    // Order Status: COMPLETED
    // Payment Status: PENDING
    return 0;
}