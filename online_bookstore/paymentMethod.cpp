#include "paymentMethod.hpp"

PaymentMethod::PaymentMethod(int id, double amount)
{
    this->id = id;
    this->amount = amount;
    this->status = PAYMENT_STATUS::PENDING;
}
double PaymentMethod::getAmount()
{
    return this->amount;
}
PAYMENT_STATUS PaymentMethod::getStatus()
{
    return this->status;
}
void PaymentMethod::setStatus(PAYMENT_STATUS status) {
    this->status = status;
}
int PaymentMethod::getId() {
    return this->id;
}