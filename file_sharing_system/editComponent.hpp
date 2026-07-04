#pragma once

#include "common.hpp"

class Component;
class User;
class AccessList;
class Folder;

class EditComponent
{
protected:
    User* user;
    AccessList* accessList;
    Folder* parent;
public:
    EditComponent(User* user, AccessList* accessList, Folder* parent);
    bool checkAccess();
    virtual void setName(string name) = 0;
};