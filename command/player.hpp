#pragma once

#include "command.hpp"

class Player {
    private:
        Command* passCommand;
    public:
        Player(Command* passCommand);
        void pass();
};