#pragma once

#include "common.hpp"
#include "item.hpp"
#include "location.hpp"

class Order;

class Restaurant
{
private:
    int id;
    string name;
    vector<Item *> items;
    Location *location;

public:
    Restaurant(int id, string name, Location *location);
    void handleOrder(Order *order);
    Item *addItem(string name, double price);
    void removeItem(Item *item);
    vector<Item *> getItems();
    Location *getLocation();
    string getName();
    int getId();
};