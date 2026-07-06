#pragma once

#include "common.hpp"
#include "chat.hpp"
#include "unordered_set"

class Profile;

class GroupChat: public Chat {
    private:
        string name;
        unordered_set<Profile*> admins;
        string createdAt;
        Profile* createdBy;
    public:
        GroupChat(int id, unordered_set<Profile*> profiles, string name, Profile* createdBy);
        string getGroupName();
        unordered_set<Profile*>& getAdmins();
        void exitGroup(Profile* profile);
        void addProfile(Profile* profile);
        void removeProfile(Profile* profile);
        void makeAdmin(Profile* profile);
        void removeAdmin(Profile* profile);
        void renameGroup(string name);
};