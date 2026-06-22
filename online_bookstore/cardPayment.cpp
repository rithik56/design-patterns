#include "cardPayment.hpp"

CardPayment::CardPayment(int id, double amount) : PaymentMethod(id, amount)
{

}
void CardPayment::makePayment() {
    cout << "payment done by card" << endl; 
    this->setStatus(PAYMENT_STATUS::SUCCESSFUL);
};

void CardPayment::reversePayment() {
    cout << "payment refunded by card" << endl; 
    this->setStatus(PAYMENT_STATUS::REFUND_SUCCESS);
};