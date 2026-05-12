#include "orderManager.hpp"
#include "user.hpp"
#include "deliveryPartner.hpp"
#include "restuarant.hpp"
#include "order.hpp"

OrderManager::OrderManager()
{
    this->partnerMatchingStrategy = nullptr;
}

mutex OrderManager::mtx;

OrderManager *OrderManager::orderManager = nullptr;

OrderManager *OrderManager::getInstance()
{
    if (orderManager == nullptr)
    {
        mtx.lock();
        if (orderManager == nullptr)
        {
            orderManager = new OrderManager();
        }
        mtx.unlock();
    }
    return orderManager;
}

unordered_map<int, User *> OrderManager::getUsers()
{
    return this->users;
}
unordered_map<int, DeliveryPartner *> OrderManager::getDeliveryPartners()
{
    return this->deliveryPartners;
}
unordered_map<int, Restaurant *> OrderManager::getRestaurants()
{
    return this->restaurants;
}
unordered_map<int, Order *> OrderManager::getOrders()
{
    return this->orders;
}
Order *OrderManager::placeOrder(User *user, Cart *cart)
{
    Order *order = new Order(newOrderId, user, cart->getRestaurant(), cart->getItems(), cart->getAmount());
    this->orders[newOrderId++] = order;
    cart->getRestaurant()->handleOrder(order);
    return order;
}
User *OrderManager::addUser(int id, string name)
{
    User *user = new User(id, name);
    this->users[id] = user;
    return user;
}
DeliveryPartner *OrderManager::addDeliveryPartner(int id, string name)
{
    DeliveryPartner* deliveryPartner  = new DeliveryPartner(id, name);
    this->deliveryPartners[id] = deliveryPartner;
    return deliveryPartner;
}
Restaurant *OrderManager::addRestaurant(int id, string name, Location* location)
{
    Restaurant *restaurant = new Restaurant(id, name, location);
    this->restaurants[id] = restaurant;
    return restaurant;
}
DeliveryPartner *OrderManager::assignOrder(Order *order)
{
    DeliveryPartner *deliveryPartner = this->partnerMatchingStrategy->assignPartner(order, this->deliveryPartners);
    if (deliveryPartner)
    {
        order->setDeliveryPartner(deliveryPartner);
        this->setOrderStatus(order, ORDER_STATUS::ASSIGNED);
    }
    return deliveryPartner;
}
void OrderManager::setPartnerMatchingStrategy(PartnerMatchingStrategy *partnerMatchingStrategy)
{
    this->partnerMatchingStrategy = partnerMatchingStrategy;
}

void OrderManager::setOrderStatus(Order *order, ORDER_STATUS orderStatus)
{
    if (orderStatus == ORDER_STATUS::COMPLETED)
    {
        order->setEndTime(chrono::system_clock::now());
    } else if (orderStatus == ORDER_STATUS::ACCEPTED) {
        this->assignOrder(order);
    } else if (orderStatus == ORDER_STATUS::ASSIGNED) {
        order->setStartTime(chrono::system_clock::now());
    }
    order->setOrderStatus(orderStatus);
}