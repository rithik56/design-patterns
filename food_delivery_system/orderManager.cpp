#include "orderManager.hpp"
#include "deliveryPartnerManager.hpp"

OrderManager *OrderManager::instance = NULL;
mutex OrderManager::mtx;

OrderManager::OrderManager()
{
}

OrderManager *OrderManager::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new OrderManager();
        }
        mtx.unlock();
    }
    return instance;
}

// pass all the necessary details here
Order *OrderManager::createOrder(User *user, Cart *cart)
{
    int orderId = newOrderId++;
    Order* order = new Order(orderId, user, cart);
    cart->getRestaurant()->handleOrder(order);
    return order;
}

// handle all the communications here
void OrderManager::updateOrderStatus(Order *order, ORDER_STATUS orderStatus)
{
    if (orderStatus == ORDER_STATUS::ACCEPTED) {
        this->assignOrder(order);
    } else if (orderStatus == ORDER_STATUS::ASSIGNED) {
        order->getDeliveryPartner()->setStatus(DRIVER_STATUS::BUSY);
    } else if (orderStatus == ORDER_STATUS::DELIVERY_SUCCESSFUL) {
        order->getDeliveryPartner()->setStatus(DRIVER_STATUS::AVAILABLE);
    }
    order->setStatus(orderStatus);
}

// run assign algorithm here
DeliveryPartner *OrderManager::assignOrder(Order *order)
{
    unordered_map<int, DeliveryPartner *> mp = DeliveryPartnerManager::getInstance()->getDeliveryPartners();
    DeliveryPartner* deliveryPartner = NULL;
    int minDistance = INT_MAX;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second->getStatus() == DRIVER_STATUS::AVAILABLE) {
            int currDist = abs(it->second->getCurrLocation()->getCoordinates().second - order->getCart()->getRestaurant()->getLocation()->getCoordinates().first) +  abs(it->second->getCurrLocation()->getCoordinates().first - order->getCart()->getRestaurant()->getLocation()->getCoordinates().second);
            if (currDist < minDistance) {
                minDistance = currDist;
                deliveryPartner = it->second;
            }
        }
    }
    order->setDeliveryPartner(deliveryPartner);
    this->updateOrderStatus(order, ORDER_STATUS::ASSIGNED);
    return deliveryPartner;
}