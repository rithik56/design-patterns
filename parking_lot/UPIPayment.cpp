#include "UPIPayment.hpp"

UPIPayment::UPIPayment(double amount): Payment(amount) {
    this->paymentMode = PAYMENT_MODE::UPI;
}

void UPIPayment::processPayment() {
    cout << "payment done by the UPI" << endl;
    this->status = PAYMENT_STATUS::PAYMENT_COMPLETED;
}   