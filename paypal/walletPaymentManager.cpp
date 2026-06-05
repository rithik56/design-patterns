#include "walletPaymentManager.hpp"
#include "walletPayment.hpp"
#include "amount.hpp"

WalletPaymentManager* WalletPaymentManager::instance = NULL;
mutex WalletPaymentManager::mtx;

WalletPaymentManager::WalletPaymentManager() {

}

WalletPaymentManager* WalletPaymentManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new WalletPaymentManager();
        }
        mtx.unlock();
    }
    return instance;
}

WalletPayment* WalletPaymentManager::createWalletPayment(FundAccount* reciever, Amount* credit, Wallet* wallet) {
    int walletPaymentId = newWalletPaymentId++;
    Amount* debit = new Amount(credit->getAmount(), credit->getCurrType());
    WalletPayment* walletPayment = new WalletPayment(walletPaymentId, reciever, debit, credit, wallet);
    this->mp[walletPaymentId] = walletPayment; 
    return walletPayment;
}