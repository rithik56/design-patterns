#pragma once

#include "common.hpp"
#include "user.hpp"
#include "deliveryPartner.hpp"
#include "restaurant.hpp"
#include "order.hpp"
#include "mutex"

class OrderManager {
    private:
        OrderManager();
        static OrderManager* orderManager;
        static mutex mtx;
        static unordered_map<int, User*> users;
        static unordered_map<int, DeliveryPartner*> deliveryPartners;
        static unordered_map<int, Restaurant*> restaurants;
        static unordered_map<int, Order*> orders;
    public:
        static OrderManager* getOrderManagerInstance();
        User* addUser(string name, string phone);
        DeliveryPartner* addDeliveryPartner(string name, string phone);
        Restaurant* addRestaurant(string name, Location* location);
        void assignOrder(Order* order);
        int getDeliveryPartnerOrderId(int deliveryPartnerId, ORDER_STATUS orderStatus);
        void startDelivery(int deliveryPartnerId);
        void completeDelivery(int deliveryPartnerId);
};