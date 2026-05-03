#include "order.hpp"
#include "item.hpp"

Order::Order(int id, User* user, Restaurant* restaurant, vector<pair<Item*, int>> items) {
    this->id = id;
    this->user = user;
    this->restaurant = restaurant;
    this->items = items;
}

void Order::setDeliveryPartner(DeliveryPartner* deliveryPartner) {
    this->deliveryPartner = deliveryPartner;
}

void Order::setPayment(Payment* payment) {
    this->payment = payment;
}

void Order::setOrderStatus(ORDER_STATUS orderStatus) {
    this->orderStatus = orderStatus;
}

int Order::getId() {
    return this->id;
}

User* Order::getUser() {
    return this->user;
}

DeliveryPartner* Order::getDeliveryPartner() {
    return this->deliveryPartner;
}

vector<pair<Item*, int>> Order::getItems() {
    return this->items;
}

PAYMENT_STATUS Order::getPaymentStatus() {
    return this->payment->getStatus();
}

double Order::getPaymentAmount() {
    return this->payment->getAmount();
}

string Order::getRestaurantName() {
    return this->restaurant->getName();
}

Location* Order::getRestaurantLocation() {
    return this->restaurant->getLocation();
}

ORDER_STATUS Order::getOrderStatus() {
    return this->orderStatus;
}

Restaurant* Order::getRestaurant() {
    return this->restaurant;
}

double Order::calculateItemsCost() {
    double amount = 0;
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        amount += (it->first->getPrice()) * (it->second);
    }
    return amount;
}

double Order::calculateDeliveryCost() {
    Location* userAddress = this->user->getAddress();
    Location* restaurantAddress = this->getRestaurantLocation();
    int dist = abs(userAddress->getLatitude() - restaurantAddress->getLatitude()) + abs(userAddress->getLongitude() - restaurantAddress->getLongitude());
    return dist * 7.4;
}

void Order::handleOrder() {
    this->restaurant->handleOrder(this);
}

void Order::processPayment() {
    this->payment->processPayment();
}