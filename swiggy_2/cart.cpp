#include "cart.hpp"

Cart::Cart()
{
    this->restaurant = nullptr;
}

void Cart::addItem(Item *item, Restaurant *restaurant)
{
    if (this->restaurant == restaurant)
    {
        this->items[item]++;
    }
    else
    {
        this->items.clear();
        this->items[item] = 1;
        this->restaurant = restaurant;
        this->amount = 0;
    }
    this->amount += item->getPrice();
}
void Cart::removeItem(Item *item)
{
    this->items[item]--;
    this->amount -= item->getPrice();
}
double Cart::getAmount()
{
    return this->amount;
}

Restaurant *Cart::getRestaurant()
{
    return this->restaurant;
}

unordered_map<Item *, int> Cart::getItems()
{
    return this->items;
}