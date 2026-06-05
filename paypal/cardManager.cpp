#include "cardManager.hpp"
#include "card.hpp"

CardManager* CardManager::instance = NULL;
mutex CardManager::mtx;

CardManager::CardManager() {

}

CardManager* CardManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new CardManager();
        }
        mtx.unlock();
    }
    return instance;
}

Card* CardManager::addCard(string cardNumber, int securityNumber, string expiry, Wallet* wallet) {
    int cardId = newCardId++;
    Card* card = new Card(cardId, cardNumber, securityNumber, expiry, wallet, FUNDING_SOURCE_STATUS::NOT_VERIFIED);
    this->mp[cardId] = card; 
    return card;
}