#pragma once

#include "common.hpp"
#include "membership.hpp"

class GoldMembership : public Membership {
    public:
        GoldMembership(int id, User* user);
        bool isEligibleForFreeDelivery(Cart* cart) override;
};