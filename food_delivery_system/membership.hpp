#pragma once

#include "common.hpp"
#include "payment.hpp"
#include "cart.hpp"

class User;

class Membership {
    protected:
        int id;
        User* user;
        MEMBERSHIP_ENUM name;
        string startDate;
        string expiryDate;
        Payment* payment;
    public:
        Membership(int id, User* user);
        virtual bool isEligibleForFreeDelivery(Cart* cart) = 0;
        void showMembershipDetails();
};