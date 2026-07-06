#pragma once 

#include "common.hpp"
#include "chatTray.hpp"

class MainTray: public ChatTray {
    public:
        MainTray(ChatSection* chatSection);
        void moveChat(Chat* chat) override;
};