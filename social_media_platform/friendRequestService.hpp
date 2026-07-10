#pragma once

#include "common.hpp"

class Profile;
class FriendRequest;

class FriendRequestService {
    private:
        FriendRequestService();
        static FriendRequestService* instance;
        static mutex mtx;
        bool checkIfFriends(Profile* sender, Profile* receiver);
        FriendRequest* checkFriendRequest(Profile* sender, Profile* receiver);
    public:
        static FriendRequestService* getInstance();
        FriendRequest* createFriendRequest(Profile* sender, Profile* receiver);
        void acceptFriendRequest(Profile* profile, FriendRequest* request);
        void rejectFriendRequest(Profile* profile, FriendRequest* request);
        void unfriend(Profile* profile1, Profile* profile2);
};