#pragma once

#include "common.hpp"

class Payment {
    protected:
        double amount;
        PAYMENT_STATUS status;
        PAYMENT_MODE paymentMode;
    public:
        Payment(double amount);
        double getAmount();
        PAYMENT_STATUS getStatus();
        PAYMENT_MODE getPaymentMode();
        virtual void processPayment() = 0;
};