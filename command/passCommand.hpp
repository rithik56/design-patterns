#pragma once

#include "command.hpp"
#include "common.hpp"
#include "ballController.hpp"

class PassCommand: public Command {
    private:
        BallController* ballController;
    public:
        PassCommand(BallController* ballController);
        void execute() override;
};