#pragma once

#include "common.hpp"
#include "payment.hpp"

class Card;
class FundAccount;

class CardPayment: public Payment {
    private:
        Card* card;
    public:
        CardPayment(int id, FundAccount* reciever, Amount* debit, Amount* credit, Card* card);
        FundAccount* getSenderFundAccount() override;
};