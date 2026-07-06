#include "messageStatus.hpp"
#include "profile.hpp"
#include "user.hpp"

MessageStatus::MessageStatus(Message *message)
{
    this->message = message;
    
}
unordered_set<Profile*>& MessageStatus::getStatusSet(MESSAGE_STATUS status) {
    if (status == MESSAGE_STATUS::DELIVERED) {
        return this->delivered;
    } else if (status == MESSAGE_STATUS::NOT_DELIVERED) {
        return this->notDelivered;
    }
    return this->seen;
}
void MessageStatus::showStatus(MESSAGE_STATUS status) {
    unordered_set<Profile*>& profiles = this->getStatusSet(status);
    for (auto it = profiles.begin(); it != profiles.end(); it++) {
        cout << (*it)->getUser()->getName() << endl;
    }
}
bool MessageStatus::isDelivered()
{
    // check if all the recivers of the chat have received the message
    return this->notDelivered.size() == 0;
}
bool MessageStatus::isSeen()
{
    // check if all the recivers of the chat have seen the message
    return this->notDelivered.size() == 0 && this->seen.size() == this->delivered.size();
}
void MessageStatus::updateStatus(Profile* profile, MESSAGE_STATUS status)
{
    if (status == MESSAGE_STATUS::DELIVERED) {
        this->notDelivered.erase(profile);
        this->delivered.insert(profile);
    } else if (status == MESSAGE_STATUS::SEEN) {
        this->seen.insert(profile);
    } else {
        this->notDelivered.insert(profile);
    }
}