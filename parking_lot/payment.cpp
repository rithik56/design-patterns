#include "payment.hpp"

Payment::Payment(double amount) {
    this->status = PAYMENT_STATUS::PENDING;
    this->amount = amount;
}

double Payment::getAmount() {
    return this->amount;
}

PAYMENT_STATUS Payment::getStatus() {
    return this->status;
}

PAYMENT_MODE Payment::getPaymentMode() {
    return this->paymentMode;
}