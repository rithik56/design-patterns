#pragma once

#include "common.hpp"
#include "payment.hpp"

class CashPayment: public Payment {
    public:
        CashPayment(double amount);
        void processPayment() override;
};