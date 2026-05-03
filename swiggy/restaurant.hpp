#pragma once

#include "common.hpp"
#include "location.hpp"

class Order;
class Item;

class Restaurant {
    private:
        unordered_map<int, Item*> items;
        string name;
        int id;
        Location* location;
    public:
        Restaurant(string name, int id, Location* location);
        void addItem(string name, double price, string description);
        void removeItem(int itemId);
        void handleOrder(Order* order);
        string getName();
        int getId();
        unordered_map<int, Item*>& getItems();
        Location* getLocation();
};