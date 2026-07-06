#include "profile.hpp"
#include "chatSection.hpp"

Profile::Profile(int id, User *user)
{
    this->id = id;
    this->user = user;
    this->chatSection = new ChatSection(this);
}
int Profile::getId()
{
    return this->id;
}
User *Profile::getUser()
{
    return this->user;
}
ChatSection *Profile::getChatSection()
{
    return this->chatSection;
}
void Profile::updateStatus(PROFILE_STATUS status)
{
    this->status = status;
}
PROFILE_STATUS Profile::getStatus()
{
    return this->status;
}