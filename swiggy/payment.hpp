#pragma once

#include "common.hpp"

class Payment {
    private:
        double amount;
        PAYMENT_STATUS status;
    public:
        Payment(double amount);
        double getAmount();
        PAYMENT_STATUS getStatus();
        void processPayment();
};