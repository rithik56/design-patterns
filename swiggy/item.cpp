#include "item.hpp"
#include "restaurant.hpp"

Item::Item(int id, string name, double price, string description, Restaurant* restaurant) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->description = description;
    this->restaurant = restaurant;
}

string Item::getName() {
    return this->name;
}

int Item::getId() {
    return this->id;
}

double Item::getPrice() {
    return this->price;
}

string Item::getDescription() {
    return this->description;
}

Restaurant* Item::getRestaurant() {
    return this->restaurant;
}