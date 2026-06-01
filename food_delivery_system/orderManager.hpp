#pragma once

#include "common.hpp"
#include "order.hpp"
#include "mutex"
#include "deliveryPartner.hpp"

class OrderManager {
    private:
        OrderManager();
        static OrderManager* instance;
        static mutex mtx;
        unordered_map<int, Order*> mp;
    public:
        static OrderManager* getInstance();
        Order* createOrder(User *user, Cart *cart);
        void updateOrderStatus(Order* order, ORDER_STATUS orderStatus);
        DeliveryPartner* assignOrder(Order* order);
};