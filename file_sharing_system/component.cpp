#include "component.hpp"
#include "accessList.hpp"
#include "folder.hpp"

Component::Component(string name, Folder* parent, User* owner)
{
    this->name = name;
    this->size =0;
    this->parent = parent;
    this->accessList = new AccessList(owner);
}

bool Component::checkAccess(User* user, ACCESS_MODE accessMode)
{
    if (this->accessList->checkUserAccess(user, accessMode))
    {
        return true;
    }
    cout << "you don't seem to have access. Please request the access from owner" << endl;
    return false;
}

string Component::getName()
{
    return this->name;
}

AccessList *Component::getAccessList()
{
    return this->accessList;
}

double Component::getSize()
{
    return this->size;
}

void Component::setName(string name) {
    this->name = name;
    this->updated_at = "22/06/2026";
}

void Component::updateSize(double diff) {
    this->size += diff;
    if (this->parent != nullptr) {
        this->parent->updateSize(diff);
    }
}

Folder* Component::getParent() {
    return this->parent;
}