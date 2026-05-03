#pragma once

#include "common.hpp"
#include "payment.hpp"

class UPIPayment: public Payment {
    public:
        UPIPayment(double amount);
        void processPayment() override;
};