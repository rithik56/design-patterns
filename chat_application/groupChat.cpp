#include "groupChat.hpp"

GroupChat::GroupChat(int id, unordered_set<Profile*> profiles, string name, Profile *createdBy) : Chat(id, profiles)
{
    this->name = name;
    this->createdBy = createdBy;
    this->createdAt = "05/07/2026";
    this->admins.insert(createdBy);
}
void GroupChat::exitGroup(Profile *profile)
{
    if (this->admins.find(profile) != this->admins.end()) {
        this->admins.erase(profile);
    }
    this->profiles.erase(profile);
}
void GroupChat::GroupChat::addProfile(Profile *profile)
{
    this->profiles.insert(profile);
}
void GroupChat::makeAdmin(Profile *profile)
{
    this->admins.insert(profile);
}
void GroupChat::removeAdmin(Profile *profile)
{
    this->admins.erase(profile);
}
void GroupChat::renameGroup(string name)
{
    this->name = name;
}
void GroupChat::removeProfile(Profile* profile) 
{
    this->profiles.erase(profile);
}
string GroupChat::getGroupName() {
    return this->name;
}
unordered_set<Profile*>& GroupChat::getAdmins() {
    return this->admins;
}
