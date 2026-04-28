#include "user.hpp"

User::User(string id, string name, string phone) {
    this->id = id;
    this->name = name;
    this->phone = phone;
}

string User::getId() {
    return this->id;
}

string User::getName() {
    return this->name;
}