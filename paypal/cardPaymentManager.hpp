#pragma once

#include "common.hpp"
#include "mutex"

class CardPayment;
class Wallet;
class Card;
class Amount;
class FundAccount;

class CardPaymentManager {
    private:
        CardPaymentManager();
        static CardPaymentManager* instance;
        static mutex mtx;
        unordered_map<int, CardPayment*> mp;
    public:
        static CardPaymentManager* getInstance();
        CardPayment* createCardPayment(FundAccount* reciever, Amount* credit, Card* card);
};