#pragma once

#include "common.hpp"

class User;
class Profile;

class ProfileService {
    private:
        unordered_map<User*, Profile*> userProfiles;
        ProfileService();
        static ProfileService* instance;
        static mutex mtx;
    public:
        static ProfileService* getInstance();
        Profile* createProfile(User* user);
        Profile* getUserProfile(User* user);
};