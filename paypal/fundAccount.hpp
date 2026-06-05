#pragma once

#include "common.hpp"

class Payment;
class Amount;

class FundAccount {
    protected:
        FUNDING_SOURCE_STATUS status;
    public:
        FundAccount(FUNDING_SOURCE_STATUS status);
        virtual void processPayment(Payment* payment) = 0;
        virtual void verifyStatus() = 0;
        virtual Amount* checkBalance() = 0;
        virtual void handleSuccessCallback(Payment* payment) = 0;
};