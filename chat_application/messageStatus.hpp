#pragma once

#include "common.hpp"
#include "unordered_set"

class Message;
class Profile;

class MessageStatus {
    private:
        Message* message;
        unordered_set<Profile*> notDelivered;
        unordered_set<Profile*> delivered;
        unordered_set<Profile*> seen;
    public:
        MessageStatus(Message* message);
        unordered_set<Profile*>& getStatusSet(MESSAGE_STATUS status);
        void showStatus(MESSAGE_STATUS status);
        void updateStatus(Profile* profile, MESSAGE_STATUS status);
        bool isSeen();
        bool isDelivered();
};