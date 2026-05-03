#pragma once

#include "common.hpp"

class Restaurant;

class Item {
    private:
        string name;
        int id;
        double price;
        string description;
        Restaurant* restaurant;
    public:
        Item(int id, string name, double price, string description, Restaurant* restaurant);
        string getName();
        int getId();
        double getPrice();
        string getDescription();
        Restaurant* getRestaurant();
};

