#pragma once

#include "common.hpp"
#include "user.hpp"
#include "mutex"
#include "location.hpp"

class UserManager {
    private:
        UserManager();
        static UserManager* instance;
        static mutex mtx;
        unordered_map<int, User*> mp;
    public:
        static UserManager* getInstance();
        User* addUser(string name, string phone, Location* location);
};