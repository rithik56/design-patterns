#pragma once

#include "common.hpp"

class Dish {
    private:
        int id;
        string name;
        double amount;
        double ratings;
    public:
        Dish(int id, string name, double amount);
        int getId();
        string getName();
        double getAmount();
        double getRatings();
        void showDishDetails();
};