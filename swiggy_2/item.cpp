#include "item.hpp"

Item::Item(int id, string name, double price)
{
    this->id = id;
    this->name = name;
    this->price = price;
}
int Item::getId()
{
    return this->id;
}
string Item::getName()
{
    return this->name;
}
double Item::getPrice()
{
    return this->price;
}