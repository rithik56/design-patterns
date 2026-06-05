#include "paymentRequestManager.hpp"
#include "paymentRequest.hpp"
#include "amount.hpp"
#include "wallet.hpp"

PaymentRequestManager* PaymentRequestManager::instance = NULL;
mutex PaymentRequestManager::mtx;

PaymentRequestManager::PaymentRequestManager() {

}

PaymentRequestManager* PaymentRequestManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new PaymentRequestManager();
        }
        mtx.unlock();
    }
    return instance;
}

PaymentRequest* PaymentRequestManager::createPaymentRequest(FundAccount* receiver, Amount *amount, Wallet* sender) {
    int paymentRequestId = newPaymentRequestId++;
    PaymentRequest* paymentRequest = new PaymentRequest(paymentRequestId, receiver, amount, sender);
    this->mp[paymentRequestId] = paymentRequest; 
    sender->addPendingPayment(paymentRequest);
    return paymentRequest;
}