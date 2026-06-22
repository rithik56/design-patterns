#include "goldMembership.hpp"
#include "paymentManager.hpp"

GoldMembership::GoldMembership(int id, User *user) : Membership(id, user)
{
    this->startDate = "01/06/2026";
    this->expiryDate = "30/08/2026";
    this->payment = PaymentManager::getInstance()->(1.0);
}

bool GoldMembership::isEligibleForFreeDelivery(Cart* cart)
{
    return cart->calculateDistance() <= 11 && cart->getItemTotal() > 99.0;
}