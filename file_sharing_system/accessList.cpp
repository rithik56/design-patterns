#include "accessList.hpp"
#include "userPermission.hpp"

AccessList::AccessList(User* owner) {
    this->owner = owner;
}

bool AccessList::checkUserAccess(User *user, ACCESS_MODE accessMode)
{
    if (this->owner == user)
    {
        return true;
    }
    if (this->userAccess.find(user) == this->userAccess.end())
    {
        return false;
    }
    return this->userAccess[user]->checkAccess(accessMode);
}
void AccessList::removeUser(User *user)
{
    this->userAccess.erase(user);
}
void AccessList::updateUserAccess(User *user, UserPermission *permission)
{
    this->userAccess[user] = permission;
}
unordered_map<User*, UserPermission*>& AccessList::getUserAccess() {
    return this->userAccess;
}
User* AccessList::getOwner() {
    return this->owner;
}