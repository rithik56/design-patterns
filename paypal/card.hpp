#pragma once

#include "common.hpp"
#include "fundAccount.hpp"

class Wallet;
class Payment;

class Card: public FundAccount {
    private:
        int id;
        string cardNumber;
        int securityNumber;
        string expiry;
        Wallet* wallet;
    public:
        Card(int id, string cardNumber, int securityNumber, string expiry, Wallet* wallet, FUNDING_SOURCE_STATUS status);
        void processPayment(Payment* payment) override;
        void verifyStatus() override;
        void handleSuccessCallback(Payment* payment) override;
        Amount* checkBalance() override;
};