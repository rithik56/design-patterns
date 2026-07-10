#pragma once

#include "common.hpp"

class Profile;

class FriendRequest {
    private:
        Profile* sender;
        Profile* receiver;
        FRIEND_REQUEST_ENUM status;
    public:
        FriendRequest(Profile* sender, Profile* receiver);
        Profile* getSender();
        Profile* getReciever();
        FRIEND_REQUEST_ENUM getStatus();
        void updateStatus(FRIEND_REQUEST_ENUM status);
};