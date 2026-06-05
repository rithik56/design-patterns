#pragma once

#include "common.hpp"
#include "payment.hpp"

class BankAccount;
class FundAccount;

class BankPayment: public Payment {
    private:
        BankAccount* bankAccount;
    public:
        BankPayment(int id, FundAccount* reciever, Amount* debit, Amount* credit, BankAccount* bankAccount);
        FundAccount* getSenderFundAccount() override;
};