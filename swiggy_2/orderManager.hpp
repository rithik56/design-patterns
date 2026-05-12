#pragma once

#include "common.hpp"
#include "cart.hpp"
#include "partnerMatchingStrategy.hpp"
#include "mutex"

class User;
class DeliveryPartner;
class Restaurant;
class Order;

class OrderManager {
    private:
        static mutex mtx;
        OrderManager();
        static OrderManager* orderManager;
        unordered_map<int, User*> users;
        unordered_map<int, DeliveryPartner*> deliveryPartners;
        unordered_map<int, Restaurant*> restaurants;
        unordered_map<int, Order*> orders;
        PartnerMatchingStrategy* partnerMatchingStrategy;
    public:
        static OrderManager* getInstance();
        unordered_map<int, User*> getUsers();
        unordered_map<int, DeliveryPartner*> getDeliveryPartners();
        unordered_map<int, Restaurant*> getRestaurants();
        unordered_map<int, Order*> getOrders();
        Order* placeOrder(User* user, Cart* cart);
        User* addUser(int id, string name);
        DeliveryPartner* addDeliveryPartner(int id, string name);
        Restaurant* addRestaurant(int id, string name, Location* location);
        DeliveryPartner* assignOrder(Order* order);
        void setPartnerMatchingStrategy(PartnerMatchingStrategy* partnerMatchingStrategy);
        void setOrderStatus(Order* order, ORDER_STATUS orderStatus);
};