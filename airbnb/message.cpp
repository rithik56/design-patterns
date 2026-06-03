#include "message.hpp"
#include "user.hpp"

Message::Message(int id, string text, User *user)
{
    this->id = id;
    this->text = text;
    this->timestamp = "timestamp";
    this->user = user;
}
int Message::getId()
{
    return this->id;
}
string Message::getText()
{
    return this->text;
}
string Message::getTimestamp()
{
    return this->timestamp;
}
User *Message::getUser()
{
    return this->user;
}
void Message::showMessage()
{
    cout << "Message Details: " << endl;
    cout << "Text: " << text << endl;
    cout << "Timestamp: " << timestamp << endl;
    cout << "User Name: " << this->user->getName() << endl;
}