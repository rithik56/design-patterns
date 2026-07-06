#pragma once

#include<iostream>
using namespace std;

enum MESSAGE_STATUS {
    DELIVERED,
    NOT_DELIVERED,
    SEEN
};

enum EMOJI_TYPE {
    LAUGHING,
    SAD,
    CRYING,
    BLESSED
};

enum MEDIA_TYPE {
    MEDIA,
    IMAGE
};

enum GENDER {
    MALE,
    FEMALE
};

enum PROFILE_STATUS {
    ONLINE,
    OFFLINE
};

enum CHAT_TRAY {
    MAIN,
    ARCHIVE
};

enum CHAT_TYPE {
    USER,
    GROUP
};

extern int profileId;
extern int userId;
extern int groupId;
extern int chatId;