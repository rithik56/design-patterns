#pragma once

#include "common.hpp"
#include "mutex"

class BankPayment;
class BankAccount;
class Amount;
class FundAccount;

class BankPaymentManager {
    private:
        BankPaymentManager();
        static BankPaymentManager* instance;
        static mutex mtx;
        unordered_map<int, BankPayment*> mp;
    public:
        static BankPaymentManager* getInstance();
        BankPayment* createBankPayment(FundAccount* reciever, Amount* credit, BankAccount* bankAccount);
};