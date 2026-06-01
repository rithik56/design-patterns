#include "userManager.hpp"
#include "restaurantManager.hpp"
#include "deliveryPartnerManager.hpp"
#include "dishManager.hpp"
#include "complaintManager.hpp"

int main() {
    UserManager* userManager = UserManager::getInstance();
    RestaurantManager* restaurantManager = RestaurantManager::getInstance();
    DeliveryPartnerManager* deliveryPartnerManager = DeliveryPartnerManager::getInstance();
    DishManager* dishManager = DishManager::getInstance();
    ComplaintManager* complaintManager = ComplaintManager::getInstance();
    User* user = userManager->addUser("rithik", "9876543210", new Location(10, 10));
    DeliveryPartner* deliveryPartner = deliveryPartnerManager->addDeliveryPartner("rahul", new Location(11, 11), "9999999999");
    deliveryPartner->setStatus(DRIVER_STATUS::AVAILABLE);
    Restaurant* restaurant = restaurantManager->addRestaurant("Haldiram", "9812345670", new Location(5, 5));
    Dish* dish1 = dishManager->addDish("Chole Bhature", 240.0);
    Dish* dish2 = dishManager->addDish("Pao Bhaji", 240.0);
    restaurant->addDish(dish1);
    restaurant->addDish(dish2);
    user->addToCart(dish1, restaurant);
    user->addToCart(dish2, restaurant);
    Order* order = user->placeOrder();
    deliveryPartner->startDelivery(order);
    deliveryPartner->completeDelivery(order);
    user->buyMembership(MEMBERSHIP_ENUM::GOLD);
    user->addToCart(dish1, restaurant);
    user->addToCart(dish2, restaurant);
    Order* order2 = user->placeOrder();
    deliveryPartner->startDelivery(order2);
    deliveryPartner->completeDelivery(order2);
    user->showOrderHistory();
    user->showMembershipDetails();
    return 0;   
}