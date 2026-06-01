#include "payment.hpp"

Payment::Payment(int amount)
{
    this->amount = amount;
    this->paymentStatus = PAYMENT_STATUS::PENDING;
}
int Payment::getAmount()
{
    return this->amount;
}
PAYMENT_STATUS Payment::getPaymentStatus()
{
    return this->paymentStatus;
}

void Payment::processPayment() {
    this->paymentStatus = PAYMENT_STATUS::SUCCESSFUL;
}