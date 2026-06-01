#pragma once

#include "common.hpp"
#include "restaurant.hpp"
#include "mutex"
#include "location.hpp"

class RestaurantManager {
    private:
        RestaurantManager();
        static RestaurantManager* instance;
        static mutex mtx;
        unordered_map<int, Restaurant*> mp;
    public:
        static RestaurantManager* getInstance();
        Restaurant* addRestaurant(string name, string phone, Location* location);
};