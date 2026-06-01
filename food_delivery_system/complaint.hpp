#pragma once

#include "common.hpp"

class User;
class Order;
class DeliveryPartner;

class Complaint {
    private:
        int id;
        COMPLAINT_TYPE type;
        Order* order;
        string query;
        COMPLAINT_STATUS complaintStatus;
    public:
        Complaint(int id, Order* order, string query, COMPLAINT_TYPE type);
        COMPLAINT_TYPE getType();
        Order* getOrder();
        COMPLAINT_STATUS getStatus();
        void setStatus(COMPLAINT_STATUS complaintStatus);
        void showDetails();
};