#include "component.hpp"

Component::Component(string name) {
    this->name = name;
    this->size = 0;
}

string Component::getName() {
    return this->name;
}

AccessList* Component::getAccessList() {
    return this->accessList;
}