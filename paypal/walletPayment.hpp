#pragma once

#include "common.hpp"
#include "payment.hpp"

class Wallet;
class FundAccount;

class WalletPayment: public Payment {
    private:
        Wallet* wallet;
    public:
        WalletPayment(int id, FundAccount* reciever, Amount* debit, Amount* credit, Wallet* wallet);
        FundAccount* getSenderFundAccount() override;
};