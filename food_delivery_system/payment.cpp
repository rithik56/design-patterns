#include "payment.hpp"

Payment::Payment(int id, double amount) {
    this->id = id;
    this->amount = amount;
    this->status = PAYMENT_STATUS::PAYMENT_PENDING;
}

int Payment::getId() {
    return this->id;
}

double Payment::getAmount() {
    return this->amount;
}

PAYMENT_STATUS Payment::getStatus() {
    return this->status;
}

void Payment::processPayment() {
    this->status = PAYMENT_STATUS::PAYMENT_SUCCESSFUL;
}

void Payment::showPaymentDetails() {
    cout << "Payment Details: " << endl;
    cout << "Amount: " << this->amount << endl;
    cout << "Status: " << this->status << endl;
}
