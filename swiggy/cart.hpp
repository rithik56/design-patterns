#pragma once

#include "item.hpp"
#include "order.hpp"
#include "user.hpp"

class Cart {
    private:
        unordered_map<Item*, int> items;
        User* user;
    public:
        Cart(User* user);
        void addItem(Item* item);
        void removeItem(Item* item);
        void deleteItem(Item* item);
        void clearItems();
        vector<Order*> getOrders();
};