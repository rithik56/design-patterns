#pragma once

#include "common.hpp"
#include "fundAccount.hpp"

class User;
class Amount;
class BankAccount;
class Card;
class Payment;
class BankPayment;
class CardPayment;
class FundAccount;
class WalletPayment;
class PaymentRequest;

class Wallet: public FundAccount {
    private:
        int id;
        User* user;
        Amount* balance;
        vector<BankAccount*> bankAccounts;
        vector<Card*> cards;
        vector<Payment*> transactionHistory;
        vector<PaymentRequest*> paymentRequests;
        vector<PaymentRequest*> pendingPayments;
    public:
        Wallet(int id, User* user, FUNDING_SOURCE_STATUS status);
        int getId();
        vector<BankAccount*>& getBankAccounts();
        vector<Card*>& getCards();
        vector<Payment*>& getPaymentHistory();
        BankAccount* linkBankAccount(string accountNumber, string IFSCCode);
        Card* linkCard(string cardNumber, int securityNumber, string expiry);
        void removeBankAccount(BankAccount* bankAccount);
        void removeCard(Card* card);
        void verifyBankAccount(BankAccount* bankAccount);
        void verifyCard(Card* card);
        WalletPayment* withdrawMoney(Amount* amount, BankAccount* bankAccount);
        BankPayment* addMoney(Amount* amount, BankAccount* bankAccount);
        BankPayment* sendMoneyFromBankAccount(Amount* amount, FundAccount* receiver, BankAccount* bankAccount);
        CardPayment* sendMoneyFromCard(Amount* amount, FundAccount* receiver, Card* card);
        PaymentRequest* requestPayment(Amount* amount, Wallet* sender);
        void processPayment(Payment* payment) override;
        void verifyStatus() override;
        Amount* checkBalance() override;
        void handleSuccessCallback(Payment* payment) override;
        vector<PaymentRequest*>& getPaymentRequests();
        vector<PaymentRequest*>& getPendingPayment();
        void addPaymentRequest(PaymentRequest* payment);
        void addPendingPayment(PaymentRequest* payment);
        BankPayment* executePendingPaymentFromBank(PaymentRequest* payment, BankAccount* BankAccount);
        CardPayment* executePendingPaymentFromCard(PaymentRequest* payment, Card* card);
};