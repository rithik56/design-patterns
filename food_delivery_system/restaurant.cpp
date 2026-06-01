#include "restaurant.hpp"
#include "order.hpp"
#include "orderManager.hpp"

Restaurant::Restaurant(int id, string name, string phone, Location* location) {
    this->id = id;
    this->name = name;
    this->location = location;
    this->ratings = 0.0;
    this->phone = phone;
    this->status = RESTAURANT_STATUS::OPEN_FOR_DELIVERY;
}

int Restaurant::getId() {
    return this->id;
}

string Restaurant::getPhone() {
    return this->phone;
}

string Restaurant::getName() {
    return this->name;
}

Location* Restaurant::getLocation() {
    return this->location;
}

vector<Dish*> Restaurant::getDishes() {
    return this->dishes;
}

double Restaurant::getRatings() {
    return this->ratings;
}

void Restaurant::handleOrder(Order* order) {
    OrderManager::getInstance()->updateOrderStatus(order, ORDER_STATUS::ACCEPTED);
}

void Restaurant::addDish(Dish* dish) {
    this->dishes.push_back(dish);
}

void Restaurant::showRestaurantDetails() {
    cout << "Restaurant Details: " << endl;
    cout << "Name: " << this->name << endl;
    this->location->showLocationCoordinates();
}