#pragma once

#include "common.hpp"
#include "dish.hpp"
#include "location.hpp"

class Order;

class Restaurant {
    private:
        int id;
        vector<Dish*> dishes;
        string name;
        string phone;
        Location* location;
        double ratings;
        RESTAURANT_STATUS status;
    public:
        Restaurant(int id, string name, string phone, Location* location);
        int getId();
        string getPhone();
        string getName();
        Location* getLocation();
        vector<Dish*> getDishes();
        double getRatings();
        void handleOrder(Order* order);
        void addDish(Dish* dish);
        void showRestaurantDetails();
};