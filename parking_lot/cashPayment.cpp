#include "cashPayment.hpp"

CashPayment::CashPayment(double amount): Payment(amount) {
    this->paymentMode = PAYMENT_MODE::CASH;
}

void CashPayment::processPayment() {
    cout << "payment done by the cash" << endl;
    this->status = PAYMENT_STATUS::PAYMENT_COMPLETED;
}   