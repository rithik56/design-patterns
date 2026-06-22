#include "membershipOrder.hpp"

MembershipOrder::MembershipOrder(int id, int userId, int membershipId, int paymentId) {
    this->id = id;
    this->userId = userId;
    this->membershipId = membershipId;
    this->paymentId = paymentId; 
}

int MembershipOrder::getId() {
    return this->id;
}