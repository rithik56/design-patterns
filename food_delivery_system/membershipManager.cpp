#include "membershipManager.hpp"
#include "goldMembership.hpp"

MembershipManager* MembershipManager::instance = NULL;
mutex MembershipManager::mtx;

MembershipManager::MembershipManager() {

}

MembershipManager* MembershipManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new MembershipManager();
        }
        mtx.unlock();
    }
    return instance;
}

Membership* MembershipManager::addMembership(User* user, MEMBERSHIP_ENUM name) {
    Membership* membership;
    int membershipId = newMembershipId++;
    if (name == MEMBERSHIP_ENUM::GOLD) {
        membership = new GoldMembership(membershipId, user);
    }
    this->mp[membershipId] = membership; 
    return membership;
}