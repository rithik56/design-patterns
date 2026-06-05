#include "userManager.hpp"
#include "bankPayment.hpp"
#include "cardPayment.hpp"
#include "wallet.hpp"
#include "user.hpp"
#include "card.hpp"
#include "bankAccount.hpp"
#include "amount.hpp"

int main() {
    User* user1 = UserManager::getInstance()->addUser("rithik", "rithik19901998@gmail.com");
    user1->completeVerification();
    Wallet* wallet1 = user1->getWallet();
    BankAccount* axisBankAccount = wallet1->linkBankAccount("**** **** **** 7731", "UTIB0001105");
    Card* idfcCard = wallet1->linkCard("**** **** **** 4464", 111, "09/30");
    wallet1->verifyCard(idfcCard);
    wallet1->verifyBankAccount(axisBankAccount);
    // 0
    cout << wallet1->checkBalance()->getAmount() << endl;
    // 100
    cout << axisBankAccount->checkBalance()->getAmount() << endl;
    wallet1->addMoney(new Amount(50, INR), axisBankAccount);
    // 50
    cout << wallet1->checkBalance()->getAmount() << endl;
    // 48
    cout << axisBankAccount->checkBalance()->getAmount() << endl;
    wallet1->withdrawMoney(new Amount(10, INR), axisBankAccount);
    // 40
    cout << wallet1->checkBalance()->getAmount() << endl;
    User* user2 = UserManager::getInstance()->addUser("rahul", "rahul19901998@gmail.com");
    user2->completeVerification();
    Wallet* wallet2 = user2->getWallet();
    PaymentRequest* paymentRequest = wallet2->requestPayment(new Amount(30, INR), wallet1);
    vector<PaymentRequest*> user1PendingRequests = wallet1->getPendingPayment();
    vector<PaymentRequest*> user2RequestPayments = wallet2->getPaymentRequests();
    // 1
    cout << user1PendingRequests.size() << endl;
    // 1
    cout << user2RequestPayments.size() << endl;
    // 0
    cout << wallet2->checkBalance()->getAmount() << endl;
    wallet1->executePendingPaymentFromCard(paymentRequest, idfcCard);
    // 30
    cout << wallet2->checkBalance()->getAmount() << endl;
    vector<Payment*> user1TransactionHistory = wallet1->getPaymentHistory();
    vector<Payment*> user2TransactionHistory = wallet2->getPaymentHistory();
    // 3
    cout << user1TransactionHistory.size() << endl;
    // 1
    cout << user2TransactionHistory.size() << endl;
    return 0;
}