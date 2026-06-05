#pragma once

#include "common.hpp"
#include "mutex"

class BankAccount;
class Wallet;

class BankAccountManager {
    private:
        BankAccountManager();
        static BankAccountManager* instance;
        static mutex mtx;
        unordered_map<int, BankAccount*> mp;
    public:
        static BankAccountManager* getInstance();
        BankAccount* addBankAccount(string accountNumber, string IFSCCode, Wallet* wallet);
};