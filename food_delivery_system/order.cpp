#include "order.hpp"
#include "paymentManager.hpp"
#include "deliveryPartner.hpp"
#include "user.hpp"

Order::Order(int id, User *user, Cart *cart)
{
    this->id = id;
    this->user = user;
    this->cart = cart;
    this->payment = PaymentManager::getInstance()->addPayment(cart->calculatePrice());
    this->deliveryPartner = NULL;
}
int Order::getId()
{
    return this->id;
}
Cart *Order::getCart()
{
    return this->cart;
}
DeliveryPartner *Order::getDeliveryPartner()
{
    return this->deliveryPartner;
}
Payment *Order::getPayment()
{
    return this->payment;
}
ORDER_STATUS Order::getStatus()
{
    return this->status;
}
void Order::setStatus(ORDER_STATUS status)
{
    this->status = status;
}
void Order::showOrderDetails()
{
    this->cart->displayItems();
    this->cart->getRestaurant()->showRestaurantDetails();
    this->deliveryPartner->showDetails();
    this->payment->showPaymentDetails();
    cout << "Order status: " << this->status << endl;
}

void Order::setDeliveryPartner(DeliveryPartner *deliveryPartner)
{
    this->deliveryPartner = deliveryPartner;
}

void Order::showComplaints()
{
    for (int i = 0; i < this->complaints.size(); i++)
    {
        this->complaints[i]->showDetails();
    }
}
void Order::addComplaint(Complaint *complaint)
{
    this->complaints.push_back(complaint);
}