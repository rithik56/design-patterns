#pragma once

#include "common.hpp"

class Wallet;
class BankAccount;

class User {
    private:
        int id;
        string name;
        string email;
        USER_ACCOUNT_STATUS status;
        Wallet* wallet;
    public:
        User(int id, string name, string email);
        int getId();
        string getName();
        string getEmail();
        USER_ACCOUNT_STATUS getStatus();
        Wallet* getWallet();
        void setStatus(USER_ACCOUNT_STATUS status);
        void completeVerification();
};