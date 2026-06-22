#pragma once

#include "common.hpp"

class PaymentMethod;

class PaymentFactory {
    private:
        PaymentFactory();
        static PaymentFactory* instance;
        static mutex mtx;
    public:
        static PaymentFactory* getInstance();
        PaymentMethod* createPayment(double amount, PAYMENT_METHOD method);
};