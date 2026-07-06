#pragma once

#include "common.hpp"
#include "unordered_set"

class Message;
class Profile;

class Chat {
    protected:
        int id;
        unordered_set<Profile*> profiles;
    public:
        Chat(int id, unordered_set<Profile*> profiles);
        int getId();
        unordered_set<Profile*>& getMembers();
};