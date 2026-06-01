#include "passCommand.hpp"

PassCommand::PassCommand(BallController* ballController) {
    this->ballController = ballController;
}

void PassCommand::execute() {
    this->ballController->pass();
}