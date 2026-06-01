#include "ballController.hpp"
#include "passCommand.hpp"
#include "player.hpp"

int main() {
    BallController* ballController = new BallController();
    PassCommand* passCommand = new PassCommand(ballController);
    Player* player = new Player(passCommand);
    player->pass();
    return 0;
}
