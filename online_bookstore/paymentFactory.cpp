#include "paymentFactory.hpp"
#include "cardPayment.hpp"
#include "upiPayment.hpp"

PaymentFactory *PaymentFactory::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new PaymentFactory();
        }
        mtx.unlock();
    }
    return instance;
}

PaymentFactory *PaymentFactory::instance = nullptr;
mutex PaymentFactory::mtx;

PaymentFactory::PaymentFactory() {
    
}

PaymentMethod* PaymentFactory::createPayment(double amount, PAYMENT_METHOD method) {
    PaymentMethod* p;
    if (method == PAYMENT_METHOD::CARD) {
        p = new CardPayment(paymentId, amount);
    } else {
        p = new UPIPayment(paymentId, amount);
    }
    paymentId++;
    return p;
}
