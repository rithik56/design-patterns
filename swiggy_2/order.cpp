#include "order.hpp"

Order::Order(int id, User *user, Restaurant *restaurant, unordered_map<Item*, int> items, double amount)
{
    this->id = id;
    this->user = user;
    this->restaurant = restaurant;
    this->items = items;
    this->deliveryPartner = nullptr;
    this->status = ORDER_STATUS::NOT_ASSIGNED;
    this->payment = new Payment(amount);
}
User *Order::getUser()
{
    return this->user;
}
DeliveryPartner *Order::getDeliveryPartner()
{
    return this->deliveryPartner;
}
Restaurant *Order::getRestaurant()
{
    return this->restaurant;
}
Payment *Order::getPayment()
{
    return this->payment;
}
ORDER_STATUS Order::getOrderStatus()
{
    return this->status;
}
unordered_map<Item*, int>& Order::getItems()
{
    return this->items;
}
chrono::system_clock::time_point Order::getStartTime()
{
    return this->startTime;
}
chrono::system_clock::time_point Order::getEndTime()
{
    return this->endTime;
}
void Order::processPayment()
{
    this->payment->processPayment();
}

void Order::setOrderStatus(ORDER_STATUS status) {
    this->status = status;
}

void Order::setEndTime(chrono::system_clock::time_point endTime) {
    this->endTime = endTime;
}

void Order::setStartTime(chrono::system_clock::time_point startTime) {
    this->startTime = startTime;
}

void Order::setDeliveryPartner(DeliveryPartner* deliveryPartner) {
    this->deliveryPartner = deliveryPartner;
}