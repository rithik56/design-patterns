#pragma once

#include<iostream>
using namespace std;

enum PAYMENT_STATUS {
    PAYMENT_PENDING,
    PAYMENT_IN_PROGRESS,
    PAYMENT_SUCCESSFUL
};

enum WALLET_STATUS {
    ACTIVE,
    NOT_ACTIVE
};

enum FUNDING_SOURCE_STATUS {
    VERIFIED,
    NOT_VERIFIED
};

enum USER_ACCOUNT_STATUS {
    VERIFICATION_PENDING,
    VERIFICATION_IN_PROGRESS,
    VERIFICATION_SUCCESSFUL
};

enum CURRENCY_TYPE {
    INR,
    USD,
    EUR
};

enum FUNDING_SOURCE_TYPE {
    BANK_ACCOUNT,
    CARD
};

enum CARD_TYPE {
    DEBIT,
    CREDIT
};

enum USER_VERIFICATION_STATUS {
    PENDING,
    IN_PROGRESS,
    SUCCESSFUL
};

enum PAYMENT_REQUEST_STATUS {
    PAID,
    NOT_PAID
};

extern unordered_map<CURRENCY_TYPE, double> currencyExchangePrice;

extern int newUserId;
extern int newWalletId;
extern int newCardId;
extern int newBankAccountId;
extern int newBankPaymentId;
extern int newCardPaymentId;
extern int newWalletPaymentId;
extern int newPaymentRequestId;