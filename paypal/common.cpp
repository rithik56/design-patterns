#include "common.hpp"

int newUserId= 1;
int newWalletId= 1;
int newCardId= 1;
int newBankAccountId= 1;
int newBankPaymentId= 1;
int newCardPaymentId= 1;
int newWalletPaymentId= 1;
int newPaymentRequestId= 1;

unordered_map<CURRENCY_TYPE, double> currencyExchangePrice = {
    make_pair(INR, 100.0),
    make_pair(USD, 1),
    make_pair(EUR, 1.16)
};