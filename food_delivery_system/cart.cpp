#include "cart.hpp"
#include "user.hpp"

Cart::Cart(User *user)
{
    this->user = user;
    this->restaurant = NULL;
}
void Cart::addDish(Restaurant *restaurant, Dish *dish)
{
    if (this->restaurant != restaurant)
    {
        this->clearCart();
        this->restaurant = restaurant;
    }
    this->mp[dish]++;
}
void Cart::removeDish(Dish *dish)
{
    this->mp[dish]--;
    if (this->mp[dish] == 0)
    {
        this->mp.erase(dish);
    }
    if (this->mp.size() == 0)
    {
        this->clearCart();
    }
}

double Cart::getItemTotal() {
    double curr = 0.0;
    for (auto it = this->mp.begin(); it != this->mp.end(); it++)
    {
        curr += it->first->getAmount() * it->second;
    } 
    return curr;
}

int Cart::calculateDistance() {
    int distance = abs(this->user->getAddress()->getCoordinates().first - this->restaurant->getLocation()->getCoordinates().first) + abs(this->user->getAddress()->getCoordinates().second - this->restaurant->getLocation()->getCoordinates().second);
    return distance;
}

double Cart::calculateDeliveryCharges() {
    double charges = 39.0 + (this->calculateDistance() * 2.0);
    return charges;
}

double Cart::calculatePrice()
{
    bool deliveryChargesWaived = this->user->isEligibleForFreeDelivery(this);
    return this->getItemTotal() + (deliveryChargesWaived ? 0.0 : this->calculateDeliveryCharges());
}

void Cart::clearCart()
{
    this->mp.clear();
    this->restaurant = NULL;
}

Restaurant *Cart::getRestaurant()
{
    return this->restaurant;
}
User *Cart::getUser()
{
    return this->user;
}
unordered_map<Dish *, int> &Cart::getDishes()
{
    return this->mp;
}

void Cart::displayItems() {
    for (auto it = this->mp.begin(); it != this->mp.end(); it++)
    {
        it->first->showDishDetails();
        cout << "Quantity: " << it->second;
        cout << endl;
    } 
}