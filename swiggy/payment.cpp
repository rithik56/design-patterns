#include "payment.hpp"

Payment::Payment(double amount) {
    this->amount = amount;
    this->status = PAYMENT_STATUS::PENDING;
}

void Payment::processPayment() {
    this->status = PAYMENT_STATUS::PAYMENT_COMPLETED;
}

double Payment::getAmount() {
    return this->amount;
}

PAYMENT_STATUS Payment::getStatus() {
    return this->status;
}