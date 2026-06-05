#include "cardPaymentManager.hpp"
#include "cardPayment.hpp"
#include "amount.hpp"

CardPaymentManager* CardPaymentManager::instance = NULL;
mutex CardPaymentManager::mtx;

CardPaymentManager::CardPaymentManager() {

}

CardPaymentManager* CardPaymentManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new CardPaymentManager();
        }
        mtx.unlock();
    }
    return instance;
}

CardPayment* CardPaymentManager::createCardPayment(FundAccount* reciever, Amount* credit, Card* card) {
    int cardPaymentId = newCardPaymentId++;
    // calculate card transfer charges and transaction fee charges which are decided by paypal (include conversion charges also)
    Amount* debit = new Amount(credit->getAmount() + 50.0, credit->getCurrType());
    CardPayment* cardPayment = new CardPayment(cardPaymentId, reciever, debit, credit, card);
    this->mp[cardPaymentId] = cardPayment; 
    return cardPayment;
}