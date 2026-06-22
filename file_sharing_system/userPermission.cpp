#include "userPermission.hpp"

UserPermission::UserPermission(unordered_set<ACCESS_MODE> modes)
{
    this->modes = modes;
}
void UserPermission::addMode(ACCESS_MODE mode)
{
    this->modes.insert(mode);
}
void UserPermission::removeMode(ACCESS_MODE mode)
{
    this->modes.erase(mode);
}
bool UserPermission::checkAccess(ACCESS_MODE mode) {
    return this->modes.find(mode) != this->modes.end();
}
unordered_set<ACCESS_MODE>& UserPermission::getModes() {
    return this->modes;
}