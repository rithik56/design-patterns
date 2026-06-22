#pragma once

#include "common.hpp"

class Component;
class AccessList;
class User;

class Link {
    private:
        int id;
        string token;
        Component* component;
        AccessList* accessList;
        string generated_at;
        string expires_at;
    public:
        Link(int id, string token, Component* component, AccessList* accessList, string expires_at);
        Component* accessComponent(User* user, ACCESS_MODE accessMode);
};