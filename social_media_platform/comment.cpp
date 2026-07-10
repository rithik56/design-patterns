#include "comment.hpp"

Comment::Comment(int id, string description, Profile *createdBy)
{
    this->id = id;
    this->description = description;
    this->createdBy = createdBy;
    this->createdAt = "09/07/2026";
}
int Comment::getId()
{
    return this->id;
}
string Comment::getDescription()
{
    return this->description;
}
Profile *Comment::getCreatedBy()
{
    return this->createdBy;
}
string Comment::getCreatedAt()
{
    return this->createdAt;
}
void Comment::setDescription(string description)
{
    this->description = description;
}