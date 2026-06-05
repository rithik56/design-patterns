#include "walletManager.hpp"
#include "wallet.hpp"

WalletManager* WalletManager::instance = NULL;
mutex WalletManager::mtx;

WalletManager::WalletManager() {

}

WalletManager* WalletManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new WalletManager();
        }
        mtx.unlock();
    }
    return instance;
}

Wallet* WalletManager::addWallet(User* user) {
    int walletId = newWalletId++;
    Wallet* wallet = new Wallet(walletId, user, FUNDING_SOURCE_STATUS::VERIFIED);
    this->mp[walletId] = wallet; 
    return wallet;
}