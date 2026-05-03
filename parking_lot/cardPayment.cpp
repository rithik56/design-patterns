#include "cardPayment.hpp"

CardPayment::CardPayment(double amount): Payment(amount) {
    this->paymentMode = PAYMENT_MODE::CARD;
}

void CardPayment::processPayment() {
    cout << "payment done by the card" << endl;
    this->status = PAYMENT_STATUS::PAYMENT_COMPLETED;
}   