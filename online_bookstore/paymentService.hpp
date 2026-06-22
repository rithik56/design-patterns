#pragma once

#include "common.hpp"

class PaymentMethod;

class PaymentService {
    private:
        PaymentService();
        static PaymentService* instance;
        static mutex mtx;
        unordered_map<int, PaymentMethod*> payments;
    public:
        static PaymentService* getInstance();
        PaymentMethod* handlePayment(double amount, PAYMENT_METHOD paymentMethod);
        void handleRefund(int paymentId);
};