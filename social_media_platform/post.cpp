#include "post.hpp"

Post::Post(int id, string description, vector<string> urls, Profile *createdBy)
{
    this->id = id;
    this->description = description;
    this->urls = urls;
    this->createdBy = createdBy;
    this->createdAt = "09/07/2026";
}
int Post::getId()
{
    return this->id;
}
string Post::getDescription()
{
    return this->description;
}
vector<string> &Post::getUrls()
{
    return this->urls;
}
Profile *Post::getCreatedBy()
{
    return this->createdBy;
}
string Post::getCreatedAt()
{
    return this->createdAt;
}
vector<Like *> &Post::getLikes()
{
    return this->likes;
}
vector<Comment *> &Post::getComments()
{
    return this->comments;
}
void Post::Post::setDescription(string description)
{
    this->description = description;
}
void Post::setUrls(vector<string> &urls)
{
    this->urls = urls;
}
void Post::setLikes(vector<Like *> &likes)
{
    this->likes = likes;
}
void Post::setComments(vector<Comment *> &comments)
{
    this->comments = comments;
}