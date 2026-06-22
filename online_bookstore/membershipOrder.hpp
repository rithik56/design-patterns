#pragma once

#include "common.hpp"

class MembershipOrder {
    private:
        int id;
        int userId;
        string purchased_at;
        int membershipId;
        int paymentId;
    public:
        MembershipOrder(int id, int userId, int membershipId, int paymentId);
        int getId();
};