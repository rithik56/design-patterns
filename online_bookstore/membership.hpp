#pragma once

#include "common.hpp"

class PaymentMethod;

class Membership {
    private:
        int id;
        MEMBERSHIP_NAME name;
        string start_date;
        string end_date;
        vector<PaymentMethod*> paymentHistory;
        double cost;
    public:
        Membership(int id, MEMBERSHIP_NAME name, string start_date, string end_date, double cost);
        int getId();
        double getCost();
        bool isActive();
        void addPayment(PaymentMethod* payment);
        void renew();
};