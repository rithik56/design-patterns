#include "paymentService.hpp"
#include "paymentFactory.hpp"
#include "paymentMethod.hpp"

PaymentService *PaymentService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new PaymentService();
        }
        mtx.unlock();
    }
    return instance;
}

PaymentService *PaymentService::instance = nullptr;
mutex PaymentService::mtx;

PaymentService::PaymentService() {
    
}

PaymentMethod* PaymentService::handlePayment(double amount, PAYMENT_METHOD paymentMethod) {
    PaymentMethod* p = PaymentFactory::getInstance()->createPayment(amount, paymentMethod);
    this->payments[p->getId()] = p;
    p->makePayment();
    return p;
}

void PaymentService::handleRefund(int paymentId) {
    PaymentMethod* p = this->payments[paymentId];
    p->setStatus(PAYMENT_STATUS::REFUND_PENDING);
    p->reversePayment();
}
