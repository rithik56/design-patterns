#include "player.hpp"

Player::Player(Command* passCommand) {
    this->passCommand = passCommand;
}

void Player::pass() {
    this->passCommand->execute();
}