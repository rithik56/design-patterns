#pragma once

#include "common.hpp"
#include "paymentMethod.hpp"

class UPIPayment: public PaymentMethod {
    public:
        UPIPayment(int id, double amount);
        void makePayment() override;
        void reversePayment() override;
};