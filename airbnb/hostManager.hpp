#pragma once

#include "common.hpp"
#include "mutex"

class Host;
class User;

class HostManager {
    private:
        HostManager();
        static HostManager* instance;
        static mutex mtx;
        unordered_map<int, Host*> mp;
    public:
        static HostManager* getInstance();
        Host* createHost(User* user);
};