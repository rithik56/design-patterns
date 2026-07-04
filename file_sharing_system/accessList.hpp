#pragma once

#include "common.hpp"

class User;
class UserPermission;

class AccessList {
    private:
        unordered_map<User*, UserPermission*> userAccess;
        User* owner; 
    public:
        AccessList(User* owner);
        bool checkUserAccess(User* user, ACCESS_MODE accessMode);
        void removeUser(User* user);
        void updateUserAccess(User* user, UserPermission* permission);
        unordered_map<User*, UserPermission*>& getUserAccess();
        User* getOwner();
};