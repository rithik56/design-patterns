#pragma once

#include "common.hpp"
#include "payment.hpp"

class CardPayment: public Payment {
    public:
        CardPayment(double amount);
        void processPayment() override;
};