#include "archiveTray.hpp"
#include "chatSection.hpp"

ArchiveTray::ArchiveTray(ChatSection *chatSection) : ChatTray(chatSection, CHAT_TRAY::ARCHIVE)
{
}
void ArchiveTray::moveChat(Chat *chat)
{
    this->chatSection->unarchiveChat(chat);
}