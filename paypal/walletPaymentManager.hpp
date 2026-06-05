#pragma once

#include "common.hpp"
#include "mutex"

class WalletPayment;
class Wallet;
class FundAccount;
class Amount;

class WalletPaymentManager {
    private:
        WalletPaymentManager();
        static WalletPaymentManager* instance;
        static mutex mtx;
        unordered_map<int, WalletPayment*> mp;
    public:
        static WalletPaymentManager* getInstance();
        WalletPayment* createWalletPayment(FundAccount* reciever, Amount* credit, Wallet* wallet);
};