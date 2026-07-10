#include "friendRequestService.hpp"
#include "profile.hpp"
#include "friendRequest.hpp"

FriendRequestService *FriendRequestService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new FriendRequestService();
        }
        mtx.unlock();
    }
    return instance;
}

FriendRequestService *FriendRequestService::instance = nullptr;
mutex FriendRequestService::mtx;

FriendRequestService::FriendRequestService()
{
}

FriendRequest *FriendRequestService::createFriendRequest(Profile *sender, Profile *receiver)
{
    FriendRequest* request;
    request = this->checkFriendRequest(sender, receiver);
    if (request) {
        cout << "Friend request already sent to this user." << endl;
        return NULL;
    }
    request = new FriendRequest(sender, receiver);
    receiver->getFriendRequests().push_back(request);
    return request;
}
void FriendRequestService::acceptFriendRequest(Profile *profile, FriendRequest *request)
{
    Profile* sender = request->getSender();
    bool areFriends = this->checkIfFriends(profile, sender);
    if (areFriends) {
        cout << "you are already friends with " << sender->getName() << endl;
        return;
    }
    if (request->getStatus() == FRIEND_REQUEST_ENUM::REJECTED) {
        cout << "you have already rejected friend request." << endl;
        return;
    }
    request->updateStatus(FRIEND_REQUEST_ENUM::ACCEPTED);
    auto it = find(profile->getFriendRequests().begin(), profile->getFriendRequests().end(), request);
    profile->getFriendRequests().erase(it);
    sender->getFriends().push_back(profile);
    profile->getFriends().push_back(sender);
}
void FriendRequestService::rejectFriendRequest(Profile *profile, FriendRequest *request)
{
    if (request->getStatus() == FRIEND_REQUEST_ENUM::ACCEPTED) {
        cout << "you have already accepted friend request." << endl;
        return;
    }
    request->updateStatus(FRIEND_REQUEST_ENUM::REJECTED);
    auto it = find(profile->getFriendRequests().begin(), profile->getFriendRequests().end(), request);
    profile->getFriendRequests().erase(it);
}
void FriendRequestService::unfriend(Profile *profile1, Profile *profile2)
{
    bool areFriends = this->checkIfFriends(profile1, profile2);
    if (!areFriends) {
        cout << "you are not friend with " << profile2->getName() << endl;
        return;
    }
    auto it1 = find(profile1->getFriends().begin(), profile1->getFriends().end(), profile2);
    auto it2 = find(profile2->getFriends().begin(), profile2->getFriends().end(), profile1);
    profile1->getFriends().erase(it1);
    profile2->getFriends().erase(it2);
}
FriendRequest *FriendRequestService::checkFriendRequest(Profile *sender, Profile *receiver)
{
    vector<FriendRequest*> requests = receiver->getFriendRequests();
    for (int i = 0; i < requests.size(); i++) {
        if (requests[i]->getSender() == sender && requests[i] ) {
            return requests[i];
        }
    }
    return NULL;
}
bool FriendRequestService::checkIfFriends(Profile* profile1, Profile* profile2) {
    vector<Profile*> friends = profile1->getFriends();
    for (int i = 0; i < friends.size(); i++) {
        if (friends[i] == profile2) {
            return true;
        }
    }
    return false;
}