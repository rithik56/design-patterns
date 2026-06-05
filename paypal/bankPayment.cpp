#include "bankPayment.hpp"
#include "bankAccount.hpp"

BankPayment::BankPayment(int id, FundAccount *receiver, Amount *debit, Amount *credit, BankAccount *bankAccount) : Payment(id, receiver, debit, credit)
{
    this->bankAccount = bankAccount;
}
FundAccount* BankPayment::getSenderFundAccount()
{
    return this->bankAccount;
};