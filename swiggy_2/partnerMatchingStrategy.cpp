#include "partnerMatchingStrategy.hpp"
#include "restuarant.hpp"

PartnerMatchingStrategy::PartnerMatchingStrategy()
{
}
DeliveryPartner *PartnerMatchingStrategy::assignPartner(Order *order, unordered_map<int, DeliveryPartner *>& deliveryPartners)
{
    DeliveryPartner *deliveryPartner = nullptr;
    Restaurant *restaurant = order->getRestaurant();
    Location *resLocation = restaurant->getLocation();
    int minDistance = INT_MAX;
    for (auto it = deliveryPartners.begin(); it != deliveryPartners.end(); it++)
    {
        DRIVER_STATUS status = it->second->getStatus();
        if (status == DRIVER_STATUS::ACTIVE)
        {
            Location *location = it->second->getCurrentLocation();
            int distance = calculateDistance(resLocation, location);
            if (distance < minDistance)
            {
                minDistance = distance;
                deliveryPartner = it->second;
            }
        }
    }
    if (deliveryPartner == nullptr)
    {
        cout << "No Delivery partner available at the moment" << endl;
    }
    return deliveryPartner;
}