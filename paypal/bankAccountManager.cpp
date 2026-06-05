#include "bankAccountManager.hpp"
#include "bankAccount.hpp"

BankAccountManager* BankAccountManager::instance = NULL;
mutex BankAccountManager::mtx;

BankAccountManager::BankAccountManager() {

}

BankAccountManager* BankAccountManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new BankAccountManager();
        }
        mtx.unlock();
    }
    return instance;
}

BankAccount* BankAccountManager::addBankAccount(string accountNumber, string IFSCCode, Wallet* wallet) {
    int bankAccountId = newBankAccountId++;
    BankAccount* bankAccount = new BankAccount(accountNumber, IFSCCode, wallet, FUNDING_SOURCE_STATUS::NOT_VERIFIED);
    this->mp[bankAccountId] = bankAccount; 
    return bankAccount;
}