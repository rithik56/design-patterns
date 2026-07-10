#pragma once

#include "common.hpp"

class Profile;

class SearchService {
    private:
        SearchService();
        unordered_map<int, Profile*> profiles;
        static SearchService* instance;
        static mutex mtx;
    public:
        static SearchService* getInstance();
        vector<Profile*> searchProfiles(string keyword);
        unordered_map<int, Profile*>& getProfiles();
        void setProfiles(unordered_map<int, Profile*>& profiles);
};