#include "amount.hpp"

Amount::Amount(double amount, CURRENCY_TYPE currType)
{
    this->amount = amount;
    this->currType = currType;
}
double Amount::getAmount()
{
    return this->amount;
}
CURRENCY_TYPE Amount::getCurrType()
{
    return this->currType;
}
void Amount::addAmount(double amount) {
    this->amount += amount;
}
void Amount::subtractAmount(double amount) {
    this->amount -= amount;
}