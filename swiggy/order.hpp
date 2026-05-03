#pragma once

#include "common.hpp"
#include "user.hpp"
#include "deliveryPartner.hpp"
#include "payment.hpp"
#include "restaurant.hpp"

class Item;

class Order {
    private:
        int id;
        User* user;
        DeliveryPartner* deliveryPartner;
        vector<pair<Item*, int>> items;
        Payment* payment;
        Restaurant* restaurant;
        ORDER_STATUS orderStatus;
    public:
        Order(int id, User* user, Restaurant* restaurant, vector<pair<Item*, int>> items);
        void setDeliveryPartner(DeliveryPartner* deliveryPartner);
        void setPayment(Payment* payment);
        void setOrderStatus(ORDER_STATUS orderStatus);
        int getId();
        User* getUser();
        DeliveryPartner* getDeliveryPartner();
        vector<pair<Item*, int>> getItems();
        PAYMENT_STATUS getPaymentStatus();
        string getRestaurantName();
        Location* getRestaurantLocation();
        Restaurant* getRestaurant();
        ORDER_STATUS getOrderStatus();
        double calculateItemsCost();
        double calculateDeliveryCost();
        double getPaymentAmount();
        void handleOrder();
        void processPayment();
};