#include "dish.hpp"

Dish::Dish(int id, string name, double amount) {
    this->id = id;
    this->name = name;
    this->amount = amount;
    this->ratings = 0.0;
}

int Dish::getId() {
    return this->id;
}

string Dish::getName() {
    return this->name;
}

double Dish::getAmount() {
    return this->amount;
}

double Dish::getRatings() {
    return this->ratings;
}

void Dish::showDishDetails() {
    cout << "Dish Details: " << endl;
    cout << "Name: " << this->name << endl;
    cout << "Price: " << this->amount << endl;
}