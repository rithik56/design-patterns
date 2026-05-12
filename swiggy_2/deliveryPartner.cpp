#include "deliveryPartner.hpp"
#include "orderManager.hpp"
#include "order.hpp"

DeliveryPartner::DeliveryPartner(int id, string name)
{
    this->id = id;
    this->name = name;
    this->status = DRIVER_STATUS::INACTIVE;
    this->currentLocation = nullptr;
}
string DeliveryPartner::getName()
{
    return this->name;
}
int DeliveryPartner::getId()
{
    return this->id;
}
void DeliveryPartner::startDelivery(Order *order)
{
    OrderManager::getInstance()->setOrderStatus(order, ORDER_STATUS::IN_PROGRESS);
}
void DeliveryPartner::completeDelivery(Order *order)
{
    OrderManager::getInstance()->setOrderStatus(order, ORDER_STATUS::COMPLETED);
}
void DeliveryPartner::setStatus(DRIVER_STATUS status)
{
    this->status = status;
}
void DeliveryPartner::setCurrentLocation(Location *currentLocation)
{
    this->currentLocation = currentLocation;
}

DRIVER_STATUS DeliveryPartner::getStatus()
{
    return this->status;
}
Location *DeliveryPartner::getCurrentLocation()
{
    return this->currentLocation;
}