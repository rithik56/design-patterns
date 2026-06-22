#include "membershipFactory.hpp"
#include "membership.hpp"

MembershipFactory *MembershipFactory::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new MembershipFactory();
        }
        mtx.unlock();
    }
    return instance;
}

MembershipFactory *MembershipFactory::instance = nullptr;
mutex MembershipFactory::mtx;

MembershipFactory::MembershipFactory() {
    
}

Membership* MembershipFactory::createMembership(MEMBERSHIP_NAME name) {
    Membership* m;
    if (name == MEMBERSHIP_NAME::MONTHLY) {
        m = new Membership(membershipId, name, "17/06/2026", "17/07/2026", 100);
    } else {
        m = new Membership(membershipId, name, "17/06/2026", "17/06/2027", 900);
    }
    this->memberships[membershipId] = m;
    membershipId++;
    return m;
}

Membership* MembershipFactory::getMembershipById(int membershipId) {
    return this->memberships[membershipId];
}