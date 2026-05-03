#pragma once

#include "common.hpp"
#include "location.hpp"

class Order;
class Cart;

class User {
    protected:
        int id;
        string name;
        string phone;
        Location* communicationAddress;
        Cart* cart;
        vector<Order*> orderHistory;
    public:
        User(int id, string name, string phone);
        int getId();
        string getName();
        Location* getAddress();
        Cart* getCart();
        void placeOrder();
        void updateCommunicationAddress(Location* communicationAddress);
        void showOrderHistory();
};