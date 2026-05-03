#include "orderManager.hpp"

OrderManager* OrderManager::orderManager = nullptr;
mutex OrderManager::mtx;
unordered_map<int, User *> OrderManager::users;
unordered_map<int, DeliveryPartner *> OrderManager::deliveryPartners;
unordered_map<int, Restaurant *> OrderManager::restaurants;
unordered_map<int, Order *> OrderManager::orders;

OrderManager::OrderManager()
{

}

OrderManager* OrderManager::getOrderManagerInstance()
{
    if (orderManager == nullptr) {
        mtx.lock();
        if (orderManager == nullptr) {
            orderManager = new OrderManager();
        }
        mtx.unlock();
    }
    return orderManager;
}

User* OrderManager::addUser(string name, string phone)
{
    User* user = new User(newUserId, name, phone);
    users[newUserId++] = user;
    return user;
}

DeliveryPartner* OrderManager::addDeliveryPartner(string name, string phone)
{
    DeliveryPartner* deliveryPartner = new DeliveryPartner(newUserId, name, phone);
    deliveryPartners[newUserId++] = deliveryPartner;
    return deliveryPartner;
}

Restaurant* OrderManager::addRestaurant(string name, Location* location)
{
    Restaurant* restaurant = new Restaurant(name, newRestaurantId, location);
    restaurants[newRestaurantId++] = restaurant;
    return restaurant;
}

void OrderManager::assignOrder(Order *order)
{
    Location *restaurantLocation = order->getRestaurantLocation();
    DeliveryPartner *nearestDeliveryPartner = nullptr;
    int minDistance = INT_MAX;
    for (auto it = deliveryPartners.begin(); it != deliveryPartners.end(); it++)
    {
        bool driverAvailability = it->second->getIsAvailable();
        Location *driverLocation = it->second->getCurrentLocation();
        if (driverAvailability)
        {
            int dist = abs(restaurantLocation->getLatitude() - driverLocation->getLatitude()) + abs(restaurantLocation->getLongitude() - driverLocation->getLongitude());
            if (dist < minDistance)
            {
                nearestDeliveryPartner = it->second;
                minDistance = dist;
            }
        }
    }
    if (nearestDeliveryPartner == nullptr) {
        cout << "no delivery partner is available" << endl; 
        return;
    }
    order->setDeliveryPartner(nearestDeliveryPartner);
    nearestDeliveryPartner->updateAvailability(false);
    order->setOrderStatus(ORDER_STATUS::ASSIGNED);
    orders[newOrderId++] = order;
}

int OrderManager::getDeliveryPartnerOrderId(int deliveryPartnerId, ORDER_STATUS orderStatus) {
    for (auto it = orders.begin(); it != orders.end(); it++) {
        if (it->second->getDeliveryPartner()->getId() == deliveryPartnerId && it->second->getOrderStatus() == orderStatus) {
            return it->first;
        }
    }
    return 0;
}

void OrderManager::startDelivery(int deliveryPartnerId) {
    int orderId = getDeliveryPartnerOrderId(deliveryPartnerId, ORDER_STATUS::ASSIGNED);
    orders[orderId]->setOrderStatus(ORDER_STATUS::STARTED);
}

void OrderManager::completeDelivery(int deliveryPartnerId) {
    int orderId = getDeliveryPartnerOrderId(deliveryPartnerId, ORDER_STATUS::STARTED);
    deliveryPartners[deliveryPartnerId]->updateAvailability(true);
    orders[orderId]->setOrderStatus(ORDER_STATUS::COMPLETED);
}