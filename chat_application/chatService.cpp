#include "chatService.hpp"
#include "profile.hpp"
#include "profile.hpp"
#include "groupChat.hpp"
#include "chatSection.hpp"
#include "message.hpp"

ChatService *ChatService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new ChatService();
        }
        mtx.unlock();
    }
    return instance;
}

ChatService *ChatService::instance = nullptr;
mutex ChatService::mtx;

ChatService::ChatService()
{
}
void ChatService::addChat(unordered_set<Profile *> &profiles, Chat *chat)
{
    for (auto it = profiles.begin(); it != profiles.end(); it++)
    {
        (*it)->getChatSection()->addChat(chat);
    }
    this->chats[chat] = {};
}
GroupChat *ChatService::createGroup(string name, unordered_set<Profile *> profiles, Profile *createdBy)
{
    GroupChat *chat = new GroupChat(chatId++, profiles, name, createdBy);
    this->addChat(profiles, chat);
    return chat;
}
Chat *ChatService::createChat(Profile *profile1, Profile *profile2)
{
    unordered_set<Profile *> profiles;
    profiles.insert(profile1);
    profiles.insert(profile2);
    Chat *chat = new Chat(chatId++, profiles);
    this->addChat(profiles, chat);
    profile1->getChatSection()->addProfileChat(chat, profile2);
    profile2->getChatSection()->addProfileChat(chat, profile1);
    return chat;
}
void ChatService::sendProfileMessage(Profile *profile1, Profile *profile2, string txt, vector<Media *> media)
{
    Chat *chat = profile1->getChatSection()->getProfileChat(profile2);
    if (chat == NULL)
    {
        chat = this->createChat(profile1, profile2);
    }
    this->sendMessage(chat, txt, profile1, media);
}
void ChatService::sendMessage(Chat *chat, string txt, Profile *profile1, vector<Media *> media)
{
    Message *message = new Message(this->chats[chat].size(), txt, profile1, chat->getMembers(), media);
    this->chats[chat].push_back(message);
    for (auto it = chat->getMembers().begin(); it != chat->getMembers().end(); it++)
    {
        profile1->getChatSection()->addMessage(chat, message);
    }
}
void ChatService::sendGroupMessage(GroupChat* chat, string txt, Profile *profile1, vector<Media *> media) {
    this->sendMessage(chat, txt, profile1, media);
}
