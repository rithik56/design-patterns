#include "walletPayment.hpp"
#include "wallet.hpp"

WalletPayment::WalletPayment(int id, FundAccount *receiver, Amount *debit, Amount *credit, Wallet* wallet) : Payment(id, receiver, debit, credit)
{
    this->wallet = wallet;
}
FundAccount* WalletPayment::getSenderFundAccount()
{
    return this->wallet;
};