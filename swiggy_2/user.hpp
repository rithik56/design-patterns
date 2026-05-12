#pragma once

#include "common.hpp"
#include "cart.hpp"
#include "restuarant.hpp"

class Order;

class User {
    private:
        int id;
        string name;
        Cart* cart;
        vector<Order*> orderHistory;
    public:
        User(int id, string name);
        int getId();
        string getName();
        Order* placeOrder();
        void showOrderHistory();
        void addItem(Item* item, Restaurant* restaurant);
        void removeItem(Item* item);
};