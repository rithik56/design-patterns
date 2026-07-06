#pragma once

#include "common.hpp"
#include "unordered_set"

class Chat;
class GroupChat;
class Profile;
class Message;
class Media;

class ChatService {
    private:
        void sendMessage(Chat *chat, string txt, Profile *profile1, vector<Media *> media);
        Chat* createChat(Profile* profile1, Profile* profile2);
        void addChat(unordered_set<Profile*>& profiles, Chat* chat);
        unordered_map<Chat*, vector<Message*>> chats;
        ChatService();
        static ChatService* instance;
        static mutex mtx;
    public:
        static ChatService* getInstance();
        GroupChat* createGroup(string name, unordered_set<Profile*> profiles, Profile* createdBy);
        void sendProfileMessage(Profile* profile1, Profile* profile2, string txt, vector<Media*> media);
        void sendGroupMessage(GroupChat* chat, string txt, Profile *profile1, vector<Media *> media);
};