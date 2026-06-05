#include "bankAccount.hpp"
#include "payment.hpp"
#include "amount.hpp"
#include "fundAccount.hpp"

BankAccount::BankAccount(string accountNumber, string IFSCCode, Wallet *wallet, FUNDING_SOURCE_STATUS status) : FundAccount(status)
{
    this->accountNumber = accountNumber;
    this->wallet = wallet;
    this->status = status;
    this->IFSCCode = IFSCCode;
    this->amount = new Amount(100, INR);
}
string BankAccount::getAccountNumber()
{
    return this->accountNumber;
}
Wallet *BankAccount::getWallet()
{
    return this->wallet;
}
FUNDING_SOURCE_STATUS BankAccount::getStatus()
{
    return this->status;
}
void BankAccount::verifyStatus()
{
    this->status = FUNDING_SOURCE_STATUS::VERIFIED;
}
void BankAccount::processPayment(Payment *payment)
{
    cout << "payment successfully executed by bank account number " << this->accountNumber << endl;
    this->amount->subtractAmount(payment->getDebitAmount()->getAmount());
    payment->setStatus(PAYMENT_SUCCESSFUL);
    payment->getReceiver()->handleSuccessCallback(payment);
};
Amount *BankAccount::checkBalance()
{
    return this->amount;
}
void BankAccount::handleSuccessCallback(Payment *payment)
{
    cout << "payment credited to bank account number: " << this->accountNumber << endl;
    this->amount->addAmount(payment->getCreditAmount()->getAmount());
}