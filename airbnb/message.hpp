#pragma once

#include "common.hpp"

class User;

class Message {
    private:
        int id;
        string text;
        string timestamp;
        User* user;
    public:
        Message(int id, string text, User* user);
        int getId();
        string getText();
        string getTimestamp();
        User* getUser();
        void showMessage();
};