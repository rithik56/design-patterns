#pragma once

#include "common.hpp"
#include "order.hpp"
#include "deliveryPartner.hpp"

class PartnerMatchingStrategy {
    public:
        PartnerMatchingStrategy();
        DeliveryPartner* assignPartner(Order* order, unordered_map<int, DeliveryPartner*>& deliveryPartners);
};