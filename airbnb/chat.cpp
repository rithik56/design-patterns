#include "chat.hpp"
#include "message.hpp"

Chat::Chat(int id, Booking *booking)
{
    this->id = id;
    this->messageId = 0;
    this->booking = booking;
}
int Chat::getId() {
    return this->id;
}
void Chat::addMessage(string message, User *user)
{
    Message *newMessage = new Message(this->messageId, message, user);
    this->messages.push_back(newMessage);
    this->messageId++;
}
void Chat::showMessages()
{
    for (int i = 0; i < this->messages.size(); i++)
    {
        this->messages[i]->showMessage();
    }
}