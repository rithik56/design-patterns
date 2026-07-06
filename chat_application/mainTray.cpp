#include "mainTray.hpp"
#include "chatSection.hpp"

MainTray::MainTray(ChatSection *chatSection) : ChatTray(chatSection, CHAT_TRAY::ARCHIVE)
{
}
void MainTray::moveChat(Chat *chat)
{
    this->chatSection->unarchiveChat(chat);
}