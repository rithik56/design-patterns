#pragma once

#include "common.hpp"

class User {
    private:
        string name;
        string phoneNumber;
        GENDER gender;
        string profilePic;
    public:
        User(string name, string phoneNumber, GENDER gender, string profilePic);
        int getId();
        string getName();
        GENDER getGender();
        string getProfilePic();
        string getPhoneNumber();
};