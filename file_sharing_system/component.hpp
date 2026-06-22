#pragma once

#include "common.hpp"

class AccessList;
class User;
class EditComponent;

class Component {
    protected:
        string name;
        double size;
        AccessList* accessList;
        string created_at;
        string updated_at;
    public:
        friend class EditComponent;
        Component(string name);
        virtual void view(User* user) = 0;
        virtual EditComponent* edit(User* user) = 0;
        string getName();
        AccessList* getAccessList();
};