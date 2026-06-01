#pragma once

#include "common.hpp"
#include "membership.hpp"
#include "mutex"
#include "location.hpp"

class MembershipManager {
    private:
        MembershipManager();
        static MembershipManager* instance;
        static mutex mtx;
        unordered_map<int, Membership*> mp;
    public:
        static MembershipManager* getInstance();
        Membership* addMembership(User* user, MEMBERSHIP_ENUM name);
};