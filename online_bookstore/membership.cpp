#include "membership.hpp"
Membership::Membership(int id, MEMBERSHIP_NAME name, string start_date, string end_date, double cost)
{
    this->id = id;
    this->name = name;
    this->start_date = start_date;
    this->end_date = end_date;
    this->cost = cost;
}
bool Membership::isActive()
{
    return true;
}

int Membership::getId()
{
    return this->id;
}
double Membership::getCost()
{
    return this->cost;
}
void Membership::addPayment(PaymentMethod* payment) {
    this->paymentHistory.push_back(payment);
}
void Membership::renew() {
    this->end_date = "17/08/2026";
}