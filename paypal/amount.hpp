#pragma once

#include "common.hpp"

class Amount {
    private:
        double amount;
        CURRENCY_TYPE currType;
    public:
        Amount(double amount, CURRENCY_TYPE currType);
        double getAmount();
        CURRENCY_TYPE getCurrType();
        void addAmount(double amount);
        void subtractAmount(double amount);
};