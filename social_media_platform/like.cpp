#include "like.hpp"

Like::Like(int id, Profile *createdBy)
{
    this->id = id;
    this->createdBy = createdBy;
}
int Like::getId()
{
    return this->id;
}
Profile *Like::getCreatedBy()
{
    return this->createdBy;
}