#include "message.hpp"
#include "messageStatus.hpp"

Message::Message(int id, string txt, Profile *sender, unordered_set<Profile*> receivers, vector<Media *> media)
{
    this->id = id;
    this->txt = txt;
    this->sender = sender;
    this->timestamp = "05/07/2026";
    this->media = media;
    MessageStatus* status = new MessageStatus(this);
    for (auto it = receivers.begin(); it != receivers.end(); it++) {
        status->updateStatus(*it, MESSAGE_STATUS::NOT_DELIVERED);
    }
    this->status = status;
}
void Message::addReaction(Reaction *reaction)
{
    this->reactions.push_back(reaction);
}
void Message::removeReaction(Reaction *reaction)
{
    auto it = find(this->reactions.begin(), this->reactions.end(), reaction);
    this->reactions.erase(it);
}
MessageStatus* Message::getMessageStatus() {
    return this->status;
}