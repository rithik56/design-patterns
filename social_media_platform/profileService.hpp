#pragma once

#include "common.hpp"

class Profile;

class ProfileService {
    private:
        ProfileService();
        static ProfileService* instance;
        static mutex mtx;
        bool checkProfile(string email);
    public:
        static ProfileService* getInstance();
        Profile* createProfile(string email, string password, string name);
};