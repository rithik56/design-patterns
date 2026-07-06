#pragma once

#include "common.hpp"
#include "unordered_set"

class Profile;
class Media;
class Reaction;
class Chat;
class MessageStatus;

class Message {
    private:
        int id;
        string txt;
        Profile* sender;
        string timestamp;
        MessageStatus* status;
        vector<Media*> media;
        vector<Reaction*> reactions;
    public:
        Message(int id, string txt, Profile* sender, unordered_set<Profile*> receivers, vector<Media*> media);
        void addReaction(Reaction* reaction);
        void removeReaction(Reaction* reaction);
        MessageStatus* getMessageStatus();
};