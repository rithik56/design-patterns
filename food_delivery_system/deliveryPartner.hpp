#pragma once

#include "common.hpp"
#include "location.hpp"

class Order;
class Complaint;

class DeliveryPartner {
    private:
        int id;
        DRIVER_STATUS status;
        Location* currLocation;
        string name;
        string phoneNumber;
        vector<Complaint*> complaintHistory;
    public:
        DeliveryPartner(int id, string name, Location* currLocation, string phoneNumber);
        DRIVER_STATUS getStatus();
        Location* getCurrLocation();
        void startDelivery(Order* order);
        void completeDelivery(Order* order);
        void showDetails();
        void setStatus(DRIVER_STATUS status);
        void setCurrLocation(Location* currLocation);
        Complaint* registerCompaint(Order* order, string query);
        void showComplaintHistory();
};