#include "chatTray.hpp"
#include "chatSection.hpp"
#include "groupChat.hpp"

ChatTray::ChatTray(ChatSection *chatSection, CHAT_TRAY tray)
{
    this->chatSection = chatSection;
    this->tray = tray;
}
vector<Chat *> ChatTray::getChats()
{
    return this->chats;
}
void ChatTray::removeChat(Chat *chat)
{
    auto it = find(this->chats.begin(), this->chats.end(), chat);
    this->chats.erase(it);
}
void ChatTray::deleteChat(Chat *chat)
{
    this->removeChat(chat);
    this->chatSection->deleteChat(chat);
}
void ChatTray::addChat(Chat *chat)
{
    this->chats.push_back(chat);
}
CHAT_TRAY ChatTray::getTrayType()
{
    return this->tray;
}