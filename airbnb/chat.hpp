#pragma once

#include "common.hpp"

class Message;
class Booking;
class User;

class Chat {
    private:
        int id;
        Booking* booking;
        vector<Message*> messages;
        int messageId;
    public:
        Chat(int id, Booking* booking);
        int getId();
        void addMessage(string message, User* user);
        void showMessages();
};