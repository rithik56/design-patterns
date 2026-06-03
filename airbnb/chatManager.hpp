#pragma once

#include "common.hpp"
#include "mutex"

class Chat;
class Booking;

class ChatManager {
    private:
        ChatManager();
        static ChatManager* instance;
        static mutex mtx;
        unordered_map<int, Chat*> mp;
    public:
        static ChatManager* getInstance();
        Chat* createChat(Booking* booking);
};