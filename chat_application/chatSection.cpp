#include "chatSection.hpp"
#include "mainTray.hpp"
#include "archiveTray.hpp"
#include "message.hpp"
#include "messageStatus.hpp"

ChatSection::ChatSection(Profile* profile)
{
    this->profile = profile;
    this->mainTray = new MainTray(this);
    this->archiveTray = new ArchiveTray(this);
}
void ChatSection::archiveChat(Chat *chat)
{
    this->archiveTray->addChat(chat);
    this->mainTray->removeChat(chat);
}
void ChatSection::unarchiveChat(Chat *chat)
{
    this->mainTray->addChat(chat);
    this->archiveTray->removeChat(chat);
}
void ChatSection::deleteChat(Chat *chat)
{
    this->chats.erase(chat);
}
void ChatSection::addChat(Chat *chat)
{
    this->chats[chat] = {};
}
void ChatSection::addProfileChat(Chat *chat, Profile *profile)
{
    this->profileChats[profile] = chat;
}
vector<Chat *> ChatSection::getAllChats()
{
    vector<Chat*> ans;
    for (auto it = this->chats.begin(); it != this->chats.end(); it++) {
        ans.push_back(it->first);
    }
    return ans;
}
vector<Message *> &ChatSection::getChatHistory(Chat *chat)
{
    return this->chats[chat];
}
void ChatSection::clearChatHistory(Chat *chat)
{
    this->chats[chat].clear();
}
Chat* ChatSection::getProfileChat(Profile* profile) {
    if (this->profileChats.find(profile) == this->profileChats.end()) {
        return NULL;
    }
    return this->profileChats[profile];
}
void ChatSection::addMessage(Chat* chat, Message* message) {
    this->chats[chat].push_back(message);
    message->getMessageStatus()->updateStatus(profile, MESSAGE_STATUS::DELIVERED);
}