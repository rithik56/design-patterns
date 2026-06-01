#pragma once

#include "common.hpp"
#include "restaurant.hpp"
#include "dish.hpp"

class User;

class Cart {
    private:
        Restaurant* restaurant;
        User* user;
        unordered_map<Dish*, int> mp;
    public:
        Cart(User* user);
        void addDish(Restaurant* restaurant, Dish* dish);
        void removeDish(Dish* dish);
        double getItemTotal();
        double calculatePrice();
        int calculateDistance();
        double calculateDeliveryCharges();
        void clearCart();
        Restaurant* getRestaurant();
        User* getUser();
        unordered_map<Dish*, int>& getDishes();
        void displayItems();
};