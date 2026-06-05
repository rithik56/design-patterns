#pragma once

#include "common.hpp"
#include "mutex"

class PaymentRequest;
class Wallet;
class FundAccount;
class Amount;

class PaymentRequestManager {
    private:
        PaymentRequestManager();
        static PaymentRequestManager* instance;
        static mutex mtx;
        unordered_map<int, PaymentRequest*> mp;
    public:
        static PaymentRequestManager* getInstance();
        PaymentRequest* createPaymentRequest(FundAccount* receiver, Amount *amount, Wallet *sender);
};