#include "restaurant.hpp"
#include "order.hpp"
#include "item.hpp"
#include "orderManager.hpp"

Restaurant::Restaurant(string name, int id, Location* location) {
    this->name = name;
    this->id = id;
    this->location = location;
}

void Restaurant::addItem(string name, double price, string description) {
    Item* item = new Item(newItemId, name, price, description, this);
    this->items[newItemId++] = item;
}

void Restaurant::removeItem(int id) {
    this->items.erase(id);
}

void Restaurant::handleOrder(Order* order) {
    // accept or reject the order 
    if (this->id == 3) {
        order->setOrderStatus(ORDER_STATUS::CANCELLED);
    } else {
        OrderManager::getOrderManagerInstance()->assignOrder(order);
    }
}

string Restaurant::getName() {
    return this->name;
}

int Restaurant::getId() {
    return this->id;
}

unordered_map<int, Item*>& Restaurant::getItems() {
    return this->items;
}

Location* Restaurant::getLocation() {
    return this->location;
}