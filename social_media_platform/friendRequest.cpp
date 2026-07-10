#include "friendRequest.hpp"

FriendRequest::FriendRequest(Profile *sender, Profile *receiver)
{
    this->sender = sender;
    this->receiver = receiver;
    this->status = FRIEND_REQUEST_ENUM::PENDING;
}
Profile *FriendRequest::getSender()
{
    return this->sender;
}
Profile *FriendRequest::getReciever()
{
    return this->receiver;
}
FRIEND_REQUEST_ENUM FriendRequest::getStatus()
{
    return this->status;
}
void FriendRequest::updateStatus(FRIEND_REQUEST_ENUM status)
{
    this->status = status;
}