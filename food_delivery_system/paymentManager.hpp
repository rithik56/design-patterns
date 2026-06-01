#pragma once

#include "common.hpp"
#include "payment.hpp"
#include "mutex"
#include "location.hpp"

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