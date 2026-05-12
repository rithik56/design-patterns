#pragma once

#include "common.hpp"
#include "item.hpp"
#include "restuarant.hpp"

class Cart {
    private:
        unordered_map<Item*, int> items;
        Restaurant* restaurant;
        double amount;
    public:
        Cart();
        void addItem(Item* item, Restaurant* restaurant);
        void removeItem(Item* item);
        double getAmount();
        Restaurant* getRestaurant();
        unordered_map<Item*, int> getItems();
};