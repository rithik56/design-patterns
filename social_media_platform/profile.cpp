#include "profile.hpp"
#include "feed.hpp"

Profile::Profile(int id, string name, string email, string password)
{
    this->id = id;
    this->email = email;
    this->password = password;
    this->name = name;
    this->feed = new Feed({});
}
int Profile::getId()
{
    return this->id;
}
string Profile::getName() {
    return this->name;
}
string Profile::getEmail()
{
    return this->email;
}
string Profile::getPassword()
{
    return this->password;
}
vector<Post *> &Profile::getPosts()
{
    return this->posts;
}
vector<FriendRequest *> &Profile::getFriendRequests()
{
    return this->friendRequests;
}
string Profile::getLastSeen()
{
    return this->lastSeen;
}
vector<Profile *>& Profile::getFriends()
{
    return this->friends;
}
Feed *Profile::getFeed()
{
    return this->feed;
}
void Profile::setEmail(string email)
{
    this->email = email;
}
void Profile::setPassword(string password)
{
    this->password = password;
}
void Profile::setPosts(vector<Post *> &posts)
{
    this->posts = posts;
}
void Profile::setFriendRequests(vector<FriendRequest *> &friendRequests)
{
    this->friendRequests = friendRequests;
}
void Profile::setLastSeen(string lastSeen)
{
    this->lastSeen = lastSeen;
}
void Profile::setFriends(vector<Profile *> &friends)
{
    this->friends = friends;
}
void Profile::setFeed(Feed *feed)
{
    this->feed = feed;
}