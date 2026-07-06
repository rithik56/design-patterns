#pragma once

#include "common.hpp"

class User;

class Reaction {
    private:
        User* user;
        EMOJI_TYPE emoji;
    public:
        Reaction(User* user, EMOJI_TYPE emoji);
        User* getUser();
        EMOJI_TYPE getEmoji();
};