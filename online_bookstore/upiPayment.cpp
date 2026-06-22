#include "upiPayment.hpp"

UPIPayment::UPIPayment(int id, double amount) : PaymentMethod(id, amount)
{

}
void UPIPayment::makePayment() {
    cout << "payment done by upi" << endl; 
    this->setStatus(PAYMENT_STATUS::SUCCESSFUL);
};

void UPIPayment::reversePayment() {
    cout << "payment refunded by UPI" << endl; 
    this->setStatus(PAYMENT_STATUS::REFUND_SUCCESS);
};