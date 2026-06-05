#include "payment.hpp"
#include "fundAccount.hpp"
#include "amount.hpp"
#include "fundAccount.hpp"

Payment::Payment(int id, FundAccount* reciever, Amount *debit, Amount *credit)
{
    this->id = id;
    this->reciever = reciever;
    this->debit = debit;
    this->credit = credit;
}

FundAccount *Payment::getReceiver() {
    return this->reciever;
}

Amount *Payment::getDebitAmount() {
    return this->debit;
}
Amount *Payment::getCreditAmount() {
    return this->credit;
}
PAYMENT_STATUS Payment::getPaymentStatus() {
    return this->status;
}
void Payment::setStatus(PAYMENT_STATUS status) {
    this->status = status;
}
void Payment::execute() {
    FundAccount* sender = this->getSenderFundAccount();
    sender->processPayment(this);
}
void Payment::showPaymentDetails() {
    cout << "Payment Details: " << endl;
}