#include "editComponent.hpp"
#include "component.hpp"
#include "accessList.hpp"

EditComponent::EditComponent(User* user, Component *component) {
    this->user = user;
    this->component = component;
}
bool EditComponent::checkAccess() {
    if (this->component->accessList->checkUserAccess(this->user, ACCESS_MODE::EDIT)) {
        return true;
    }
    cout << "your access seems to get revoked. Please request the access from owner" << endl;
    return false;
}
void EditComponent::setName(string name) {
    if (this->checkAccess()) {
        this->component->name = name;
    }
}