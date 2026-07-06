#include "chat.hpp"

Chat::Chat(int id, unordered_set<Profile*> profiles)
{
    this->id = id;
    this->profiles = profiles;
}
int Chat::getId()
{
    return this->id;
}
unordered_set<Profile*>& Chat::getMembers() 
{
    return this->profiles;
}