#include "user.hpp"
#include "wallet.hpp"
#include "walletManager.hpp"

User::User(int id, string name, string email)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->status = USER_ACCOUNT_STATUS::VERIFICATION_PENDING;
    this->wallet = WalletManager::getInstance()->addWallet(this);
}
int User::getId()
{
    return this->id;
}
string User::getName()
{
    return this->name;
}
string User::getEmail()
{
    return this->email;
}
USER_ACCOUNT_STATUS User::getStatus()
{
    return this->status;
}
Wallet *User::getWallet()
{
    return this->wallet;
}
void User::setStatus(USER_ACCOUNT_STATUS status) {
    this->status = status;
}
void User::completeVerification()
{
    this->setStatus(USER_ACCOUNT_STATUS::VERIFICATION_SUCCESSFUL);
}