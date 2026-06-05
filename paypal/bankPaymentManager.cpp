#include "bankPaymentManager.hpp"
#include "bankPayment.hpp"
#include "amount.hpp"

BankPaymentManager* BankPaymentManager::instance = NULL;
mutex BankPaymentManager::mtx;

BankPaymentManager::BankPaymentManager() {

}

BankPaymentManager* BankPaymentManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new BankPaymentManager();
        }
        mtx.unlock();
    }
    return instance;
}

BankPayment* BankPaymentManager::createBankPayment(FundAccount* reciever, Amount* credit, BankAccount* bankAccount) {
    int bankPaymentId = newBankPaymentId++;
    // calculate bank account transfer charges and transaction fee charges which are decided by paypal
    Amount* debit = new Amount(credit->getAmount() + 2.0, credit->getCurrType());
    BankPayment* bankPayment = new BankPayment(bankPaymentId, reciever, debit, credit, bankAccount);
    this->mp[bankPaymentId] = bankPayment; 
    return bankPayment;
}