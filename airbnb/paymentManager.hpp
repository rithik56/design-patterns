#pragma once

#include "common.hpp"
#include "mutex"

class Payment;

class PaymentManager {
    private:
        PaymentManager();
        static PaymentManager* instance;
        static mutex mtx;
        unordered_map<int, Payment*> mp;
    public:
        static PaymentManager* getInstance();
        Payment* addPayment(double amount);
};