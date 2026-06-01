#pragma once

#include "command.hpp"

class Command {
    public:
        virtual void execute() = 0;
};