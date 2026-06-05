#include "card.hpp"
#include "payment.hpp"
#include "fundAccount.hpp"

Card::Card(int id, string cardNumber, int securityNumber, string expiry, Wallet *wallet, FUNDING_SOURCE_STATUS status) : FundAccount(status)
{
    this->id = id;
    this->cardNumber = cardNumber;
    this->securityNumber = securityNumber;
    this->expiry = expiry;
    this->wallet = wallet;
}

void Card::processPayment(Payment* payment) {
    cout << "payment successfully executed by card number " << this->cardNumber << endl;
    payment->setStatus(PAYMENT_SUCCESSFUL);
    payment->getReceiver()->handleSuccessCallback(payment);
}

void Card::verifyStatus()
{
    this->status = FUNDING_SOURCE_STATUS::VERIFIED;
}

Amount *Card::checkBalance()
{
    return NULL;
}

void Card::handleSuccessCallback(Payment *payment)
{
    
}