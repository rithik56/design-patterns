#include "wallet.hpp"
#include "amount.hpp"
#include "bankAccountManager.hpp"
#include "cardManager.hpp"
#include "bankAccount.hpp"
#include "card.hpp"
#include "bankPaymentManager.hpp"
#include "cardPaymentManager.hpp"
#include "bankPayment.hpp"
#include "cardPayment.hpp"
#include "walletPaymentManager.hpp"
#include "walletPayment.hpp"
#include "fundAccount.hpp"
#include "paymentRequest.hpp"
#include "paymentRequestManager.hpp"

Wallet::Wallet(int id, User *user, FUNDING_SOURCE_STATUS status) : FundAccount(status)
{
    this->id = id;
    this->user = user;
    this->balance = new Amount(0, INR);
}
int Wallet::getId()
{
    return this->id;
}
vector<BankAccount *> &Wallet::getBankAccounts()
{
    return this->bankAccounts;
}
vector<Card *> &Wallet::getCards()
{
    return this->cards;
}
vector<Payment *> &Wallet::getPaymentHistory()
{
    return this->transactionHistory;
}
BankAccount *Wallet::linkBankAccount(string accountNumber, string IFSCCode)
{
    BankAccount *bankAccount = BankAccountManager::getInstance()->addBankAccount(accountNumber, IFSCCode, this);
    this->bankAccounts.push_back(bankAccount);
    return bankAccount;
}
Card *Wallet::linkCard(string cardNumber, int securityNumber, string expiry)
{
    Card *card = CardManager::getInstance()->addCard(cardNumber, securityNumber, expiry, this);
    this->cards.push_back(card);
    return card;
}
void Wallet::removeBankAccount(BankAccount *bankAccount)
{
    auto it = find(this->bankAccounts.begin(), this->bankAccounts.end(), bankAccount);
    this->bankAccounts.erase(it);
}
void Wallet::removeCard(Card *card)
{
    auto it = find(this->cards.begin(), this->cards.end(), card);
    this->cards.erase(it);
}
void Wallet::verifyBankAccount(BankAccount *bankAccount)
{
    bankAccount->verifyStatus();
}
void Wallet::verifyCard(Card *card)
{
    card->verifyStatus();
}
WalletPayment *Wallet::withdrawMoney(Amount *amount, BankAccount *bankAccount)
{
    WalletPayment *payment = WalletPaymentManager::getInstance()->createWalletPayment(bankAccount, amount, this);
    this->processPayment(payment);
    return payment;
}
BankPayment *Wallet::addMoney(Amount *amount, BankAccount *bankAccount)
{
    BankPayment *payment = BankPaymentManager::getInstance()->createBankPayment(this, amount, bankAccount);
    bankAccount->processPayment(payment);
    return payment;
}
BankPayment *Wallet::sendMoneyFromBankAccount(Amount *amount, FundAccount *receiver, BankAccount *bankAccount)
{
    BankPayment *payment = BankPaymentManager::getInstance()->createBankPayment(receiver, amount, bankAccount);
    this->transactionHistory.push_back(payment);
    bankAccount->processPayment(payment);
    return payment;
}
CardPayment *Wallet::sendMoneyFromCard(Amount *amount, FundAccount *receiver, Card *card)
{
    CardPayment *payment = CardPaymentManager::getInstance()->createCardPayment(receiver, amount, card);
    this->transactionHistory.push_back(payment);
    card->processPayment(payment);
    return payment;
}
PaymentRequest* Wallet::requestPayment(Amount *amount, Wallet* sender)
{ 
    PaymentRequest* request = PaymentRequestManager::getInstance()->createPaymentRequest(this, amount, sender);
    this->paymentRequests.push_back(request);
    return request;
}
void Wallet::processPayment(Payment *payment)
{
    this->transactionHistory.push_back(payment);
    cout << "payment successfully executed by wallet with id: " << this->id << endl;
    this->balance->subtractAmount(payment->getDebitAmount()->getAmount());
    payment->setStatus(PAYMENT_SUCCESSFUL);
    payment->getReceiver()->handleSuccessCallback(payment);
}
void Wallet::verifyStatus()
{
    this->status = FUNDING_SOURCE_STATUS::VERIFIED;
}
Amount *Wallet::checkBalance()
{
    return this->balance;
}
void Wallet::handleSuccessCallback(Payment *payment)
{
    cout << "payment credited to wallet with id: " << this->id << endl;
    this->balance->addAmount(payment->getCreditAmount()->getAmount());
    this->transactionHistory.push_back(payment);
}
vector<PaymentRequest *> &Wallet::getPaymentRequests()
{
    return this->paymentRequests;
}
vector<PaymentRequest *> &Wallet::getPendingPayment()
{
    return this->pendingPayments;
}
void Wallet::addPaymentRequest(PaymentRequest *payment)
{
    this->paymentRequests.push_back(payment);
}
void Wallet::addPendingPayment(PaymentRequest *payment)
{
    this->pendingPayments.push_back(payment);
}
BankPayment* Wallet::executePendingPaymentFromBank(PaymentRequest* payment, BankAccount* bankAccount) {
    return this->sendMoneyFromBankAccount(payment->getAmount(), payment->getReceiver(), bankAccount);
}
CardPayment* Wallet::executePendingPaymentFromCard(PaymentRequest* payment, Card* card) {
    return this->sendMoneyFromCard(payment->getAmount(), payment->getReceiver(), card);
}