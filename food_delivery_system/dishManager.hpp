#pragma once

#include "common.hpp"
#include "dish.hpp"
#include "mutex"

class DishManager {
    private:
        DishManager();
        static DishManager* instance;
        static mutex mtx;
        unordered_map<int, Dish*> mp;
    public:
        static DishManager* getInstance();
        Dish* addDish(string name, double price);
};