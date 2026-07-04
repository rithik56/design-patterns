#include "editComponent.hpp"
#include "component.hpp"
#include "accessList.hpp"
#include "folder.hpp"
#include "user.hpp"
#include "plan.hpp"

EditComponent::EditComponent(User *user, AccessList *accessList, Folder* parent)
{
    this->user = user;
    this->accessList = accessList;
    this->parent = parent;
}
bool EditComponent::checkAccess()
{
    if (this->accessList->checkUserAccess(this->user, ACCESS_MODE::EDIT))
    {
        return true;
    }
    cout << "your access seems to get revoked. Please request the access from owner" << endl;
    return false;
}