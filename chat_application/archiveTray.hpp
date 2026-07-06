#pragma once 

#include "common.hpp"
#include "chatTray.hpp"

class ArchiveTray: public ChatTray {
    public:
        ArchiveTray(ChatSection* chatSection);
        void moveChat(Chat* chat) override;
};