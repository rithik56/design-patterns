#pragma once

#include "common.hpp"
#include "deliveryPartner.hpp"
#include "mutex"

class DeliveryPartnerManager {
    private:
        DeliveryPartnerManager();
        static DeliveryPartnerManager* instance;
        static mutex mtx;
        unordered_map<int, DeliveryPartner*> mp;
    public:
        static DeliveryPartnerManager* getInstance();
        DeliveryPartner* addDeliveryPartner(string name, Location* currLocation, string phoneNumber);
        unordered_map<int, DeliveryPartner*>& getDeliveryPartners();
};