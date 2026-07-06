#include "reaction.hpp"

Reaction::Reaction(User *user, EMOJI_TYPE emoji)
{
    this->user = user;
    this->emoji = emoji;
}
User *Reaction::getUser()
{
    return this->user;
}
EMOJI_TYPE Reaction::getEmoji()
{
    return this->emoji;
}