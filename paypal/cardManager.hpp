#pragma once

#include "common.hpp"
#include "mutex"

class Card;
class Wallet;

class CardManager {
    private:
        CardManager();
        static CardManager* instance;
        static mutex mtx;
        unordered_map<int, Card*> mp;
    public:
        static CardManager* getInstance();
        Card* addCard(string cardNumber, int securityNumber, string expiry, Wallet* wallet);
};