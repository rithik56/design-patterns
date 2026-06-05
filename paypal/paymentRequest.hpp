#pragma once

#include "common.hpp"

class FundAccount;
class Amount;
class Wallet;

class PaymentRequest {
    private:
        int id;
        FundAccount* receiver;
        Amount* amount;
        Wallet* sender;
        PAYMENT_REQUEST_STATUS status;
    public:
        PaymentRequest(int id, FundAccount* receiver, Amount* amount, Wallet* sender);
        int getId();
        FundAccount* getReceiver();
        Amount* getAmount();
        Wallet* getSender();
        PAYMENT_REQUEST_STATUS getStatus();
        void setStatus(PAYMENT_REQUEST_STATUS status);
};