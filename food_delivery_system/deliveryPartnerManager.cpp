#include "deliveryPartnerManager.hpp"

DeliveryPartnerManager* DeliveryPartnerManager::instance = NULL;
mutex DeliveryPartnerManager::mtx;

DeliveryPartnerManager::DeliveryPartnerManager() {

}

DeliveryPartnerManager* DeliveryPartnerManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new DeliveryPartnerManager();
        }
        mtx.unlock();
    }
    return instance;
}

DeliveryPartner* DeliveryPartnerManager::addDeliveryPartner(string name, Location* currLocation, string phoneNumber) {
    int deliveryPartnerId = newDeliveryPartnerId++;
    DeliveryPartner* deliveryPartner = new DeliveryPartner(deliveryPartnerId, name, currLocation, phoneNumber);
    this->mp[deliveryPartnerId] = deliveryPartner; 
    return deliveryPartner;
}

unordered_map<int, DeliveryPartner*>& DeliveryPartnerManager::getDeliveryPartners() {
    return this->mp;
}