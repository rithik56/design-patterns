#pragma once

#include "common.hpp"

class Item {
    private:
        int id;
        string name;
        double price;
    public:
        Item(int id, string name, double price);
        int getId();
        string getName();
        double getPrice();
};