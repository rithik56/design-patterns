#pragma once

#include "common.hpp"
#include "payment.hpp"
#include "chrono"
#include "item.hpp"

class User;
class DeliveryPartner;
class Restaurant;

class Order {
    private:
        int id;
        User* user;
        DeliveryPartner* deliveryPartner;
        Restaurant* restaurant;
        Payment* payment;
        ORDER_STATUS status;
        unordered_map<Item*, int> items;
        chrono::system_clock::time_point startTime;
        chrono::system_clock::time_point endTime;
    public:
        Order(int id, User* user, Restaurant* restaurant, unordered_map<Item*, int> items, double amount);
        User* getUser();
        DeliveryPartner* getDeliveryPartner();
        Restaurant* getRestaurant();
        Payment* getPayment();
        ORDER_STATUS getOrderStatus();
        unordered_map<Item*, int>& getItems();
        chrono::system_clock::time_point getStartTime();
        chrono::system_clock::time_point getEndTime();
        void processPayment();
        void setOrderStatus(ORDER_STATUS status);
        void setEndTime(chrono::system_clock::time_point endTime);
        void setStartTime(chrono::system_clock::time_point startTime);
        void setDeliveryPartner(DeliveryPartner* deliveryPartner);
};