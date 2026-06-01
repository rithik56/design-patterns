#include "membership.hpp"
#include "user.hpp"

Membership::Membership(int id, User* user) {
    this->id = id;
    this->user = user;
}

void Membership::showMembershipDetails() {
    cout << "Membership Details:" << endl;
    cout << "Name: " << this->name << endl;
    cout << "Start Date: " << this->startDate << endl;
    cout << "Expiry Date: " << this->expiryDate << endl;
    cout << "Membership Cost: " << this->payment->getAmount() << endl;
}