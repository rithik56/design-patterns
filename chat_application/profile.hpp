#pragma once

#include "common.hpp"

class Chat;
class User;
class ChatSection;

class Profile {
    private:
        int id;
        User* user;
        ChatSection* chatSection;
        PROFILE_STATUS status;
    public:
        Profile(int id, User* user);
        int getId();
        User* getUser();
        ChatSection* getChatSection();
        void updateStatus(PROFILE_STATUS status);
        PROFILE_STATUS getStatus();
};