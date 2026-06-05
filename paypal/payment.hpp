#pragma once

#include "common.hpp"

class FundAccount;
class Amount;

class Payment {
    protected:
        int id;
        FundAccount* reciever;
        Amount* debit;
        Amount* credit;
        PAYMENT_STATUS status;
    public:
        Payment(int id, FundAccount* reciever, Amount* debit, Amount* credit);
        virtual FundAccount* getSenderFundAccount() = 0;
        void execute();
        int getId();
        FundAccount* getReceiver();
        Amount* getDebitAmount();
        Amount* getCreditAmount();
        PAYMENT_STATUS getPaymentStatus();
        void setStatus(PAYMENT_STATUS status);
        void showPaymentDetails();
};