#include "user.hpp"

User::User(string name, string phoneNumber, GENDER gender, string profilePic)
{
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->gender = gender;
    this->profilePic = profilePic;
}
string User::getName()
{
    return this->name;
}
GENDER User::getGender()
{
    return this->gender;
}
string User::getProfilePic()
{
    return this->profilePic;
}
string User::getPhoneNumber() {
    return this->phoneNumber;
}