#include "link.hpp"
#include "accessList.hpp"

Link::Link(int id, string token, Component *component, AccessList *accessList, string expires_at)
{
    this->id = id;
    this->token = token;
    this->component = component;
    this->accessList = accessList;
    this->expires_at = "27/06/2026";
    this->generated_at = "20/06/2026";
}
Component* Link::accessComponent(User *user, ACCESS_MODE accessMode)
{
    bool access = this->accessList->checkUserAccess(user, accessMode);
    if (access) {
        return this->component;
    }
    cout << "You don't have the required access for the component. Please request the acces from the owner." << endl;
    return nullptr;
}