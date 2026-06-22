#pragma once

#include "common.hpp"
#include "unordered_set"

class UserPermission {
    private:
        unordered_set<ACCESS_MODE> modes;
    public:
        UserPermission(unordered_set<ACCESS_MODE> modes);
        void addMode(ACCESS_MODE mode);
        void removeMode(ACCESS_MODE mode);
        bool checkAccess(ACCESS_MODE mode);
        unordered_set<ACCESS_MODE>& getModes();
};