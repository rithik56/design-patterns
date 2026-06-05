#include "cardPayment.hpp"
#include "card.hpp"

CardPayment::CardPayment(int id, FundAccount* receiver, Amount *debit, Amount *credit, Card *card) : Payment(id, receiver, debit, credit)
{
    this->card = card;
}
FundAccount* CardPayment::getSenderFundAccount()
{
    return this->card;
};