#pragma once

#include "common.hpp"

class Component;
class User;

class EditComponent
{
protected:
    User* user;
    Component *component;
public:
    EditComponent(User* user, Component *component);
    bool checkAccess();
    void setName(string name);
    virtual void uploadComponent(Component *component) {};
    virtual Component* createComponent(string name) {};
    virtual void deleteComponent(Component *component) {};
    virtual void updateComponent(string blob) {}
};