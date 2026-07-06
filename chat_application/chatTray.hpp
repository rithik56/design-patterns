#pragma once

#include "common.hpp"

class Chat;
class ChatSection;

class ChatTray {
    protected:
        CHAT_TRAY tray;
        ChatSection* chatSection;
        vector<Chat*> chats;
    public:
        ChatTray(ChatSection* chatSection, CHAT_TRAY tray);
        CHAT_TRAY getTrayType();
        vector<Chat*> getChats();
        void deleteChat(Chat* chat);
        void addChat(Chat* chat);
        void removeChat(Chat* chat);
        virtual void moveChat(Chat* chat) = 0;
};