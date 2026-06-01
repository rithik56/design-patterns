#pragma once

#include "common.hpp"

class Payment {
    private:
        int amount;
        PAYMENT_STATUS paymentStatus;
    public:
        Payment(int amount);
        int getAmount();
        PAYMENT_STATUS getPaymentStatus();
        void processPayment();
};