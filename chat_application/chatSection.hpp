#pragma once

#include "common.hpp"
#include "unordered_set"

class MainTray;
class ArchiveTray;
class Chat;
class Message;
class Profile;
class GroupChat;

class ChatSection {
    private:
        Profile* profile;
        unordered_map<Profile*, Chat*> profileChats;
        unordered_map<Chat*, vector<Message*>> chats;
        MainTray* mainTray;
        ArchiveTray* archiveTray;
    public:
        ChatSection(Profile* profile);
        void addProfileChat(Chat *chat, Profile* profile);
        void addChat(Chat* chat);
        void deleteChat(Chat *chat);
        void archiveChat(Chat* chat);
        void unarchiveChat(Chat* chat);
        vector<Chat*> getAllChats();
        vector<Message*>& getChatHistory(Chat* chat);
        void clearChatHistory(Chat* chat);
        void addMessage(Chat* chat, Message* message);
        Chat* getProfileChat(Profile* profile);
};