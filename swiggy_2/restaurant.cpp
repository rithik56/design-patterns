#include "restuarant.hpp"
#include "order.hpp"
#include "orderManager.hpp"

Restaurant::Restaurant(int id, string name, Location *location)
{
    this->id = id;
    this->name = name;
    this->location = location;
}
void Restaurant::handleOrder(Order *order)
{
    OrderManager::getInstance()->setOrderStatus(order, ORDER_STATUS::ACCEPTED);
}
Item *Restaurant::addItem(string name, double price)
{
    Item *item = new Item((int)this->items.size() + 1, name, price);
    this->items.push_back(item);
    return item;
}
void Restaurant::removeItem(Item *item)
{
    auto it = find(this->items.begin(), this->items.end(), item);
    this->items.erase(it);
}
vector<Item *> Restaurant::getItems()
{
    return this->items;
}

Location *Restaurant::getLocation()
{
    return this->location;
}

string Restaurant::getName()
{
    return this->name;
}
int Restaurant::getId()
{
    return this->id;
}