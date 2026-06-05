#pragma once

#include "common.hpp"
#include "mutex"

class Wallet;
class User;

class WalletManager {
    private:
        WalletManager();
        static WalletManager* instance;
        static mutex mtx;
        unordered_map<int, Wallet*> mp;
    public:
        static WalletManager* getInstance();
        Wallet* addWallet(User* user);
};