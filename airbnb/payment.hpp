#pragma once

#include "common.hpp"

class Payment {
    private:
        int id;
        double amount;
        PAYMENT_STATUS status;
    public:
        Payment(int id, double amount);
        int getId();
        double getAmount();
        PAYMENT_STATUS getStatus();
        void processPayment();
        void showPaymentDetails();
};