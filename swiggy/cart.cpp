#include "cart.hpp"
#include "restaurant.hpp"

Cart::Cart(User* user) {
    this->user = user;
}

void Cart::addItem(Item* item) {
    this->items[item]++;
}

void Cart::removeItem(Item* item) {
    this->items[item]--;
}

void Cart::deleteItem(Item* item) {
    this->items.erase(item);
}

vector<Order*> Cart::getOrders() {
    unordered_map<Restaurant*, vector<pair<Item*, int>>> restaurantsMap;
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        Restaurant* res = it->first->getRestaurant();
        restaurantsMap[res].push_back(make_pair(it->first, it->second));
    }
    vector<Order*> orders;
    for (auto it = restaurantsMap.begin(); it != restaurantsMap.end(); it++) {
        Order* order = new Order(newOrderId++, this->user, it->first, it->second);
        order->setPayment(new Payment(order->calculateDeliveryCost() + order->calculateItemsCost()));
        orders.push_back(order);
    }
    return orders;
}

void Cart::clearItems() {
    this->items.clear();
}