#pragma once

#include "common.hpp"

class AccessList;
class User;
class EditComponent;
class Folder;

class Component {
    protected:
        string name;
        double size;
        AccessList* accessList;
        string created_at;
        string updated_at;
        Folder* parent;
    public:
        Component(string name, Folder* parent, User* owner);
        virtual void view(User* user) = 0;
        virtual EditComponent* edit(User* user) = 0;
        string getName();
        bool checkAccess(User* user, ACCESS_MODE mode);
        void setName(string name);
        void updateSize(double diff);
        double getSize();
        AccessList* getAccessList();
        Folder* getParent();
};