#include "payment.hpp"

Payment::Payment(double amount) {
    this->amount = amount;
    this->status = PAYMENT_STATUS::PENDING;
}
  
double Payment::getAmount() {
    return this->amount;
}

PAYMENT_STATUS Payment::getPaymentStatus() {
    return this->status;
}

void Payment::processPayment() {
    this->status = PAYMENT_STATUS::PAYMENT_COMPLETED;
}