#pragma once

#include "common.hpp"

class Membership;

class MembershipFactory {
    private:
        MembershipFactory();
        static MembershipFactory* instance;
        static mutex mtx;
        unordered_map<int, Membership*> memberships;
    public:
        static MembershipFactory* getInstance();
        Membership* createMembership(MEMBERSHIP_NAME name);
        Membership* getMembershipById(int membershipId);
};