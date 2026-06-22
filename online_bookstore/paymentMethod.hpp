#pragma once

#include "common.hpp"

class PaymentMethod {
    private:
        int id;
        double amount;
        PAYMENT_STATUS status;
    public:
        PaymentMethod(int id, double amount);
        int getId();
        double getAmount();
        PAYMENT_STATUS getStatus();
        void setStatus(PAYMENT_STATUS status);
        virtual void makePayment() = 0;
        virtual void reversePayment() = 0;
};