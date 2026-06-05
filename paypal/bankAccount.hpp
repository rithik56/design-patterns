#pragma once

#include "common.hpp"
#include "fundAccount.hpp"

class Wallet;
class Payment;
class Amount;

class BankAccount: public FundAccount {
    private:
        Amount* amount;
        string accountNumber;
        string IFSCCode;
        Wallet* wallet;
    public:
        BankAccount(string accountNumber, string IFSCCode, Wallet* wallet, FUNDING_SOURCE_STATUS status);
        string getAccountNumber();
        Wallet* getWallet();
        FUNDING_SOURCE_STATUS getStatus();
        void verifyStatus() override;
        void processPayment(Payment* payment) override;
        Amount* checkBalance() override;
        void handleSuccessCallback(Payment* payment) override;
};