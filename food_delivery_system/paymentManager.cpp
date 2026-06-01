#include "paymentManager.hpp"

PaymentManager* PaymentManager::instance = NULL;
mutex PaymentManager::mtx;

PaymentManager::PaymentManager() {

}

PaymentManager* PaymentManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new PaymentManager();
        }
        mtx.unlock();
    }
    return instance;
}

Payment* PaymentManager::addPayment(double amount) {
    int paymentId = newPaymentId++;
    Payment* payment = new Payment(paymentId, amount);
    this->mp[paymentId] = payment; 
    return payment;
}