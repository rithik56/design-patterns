#pragma once

#include "common.hpp"
#include "paymentMethod.hpp"

class CardPayment: public PaymentMethod {
    public:
        CardPayment(int id, double amount);
        void makePayment() override;
        void reversePayment() override;
};