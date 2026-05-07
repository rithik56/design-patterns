#include "user.hpp"

#include "leetcode.hpp"

User::User(int id, string name, USER_TYPE userType) {
    this->id = id;
    this->name = name;
    this->userType = userType;
}

void User::submitSolution(int question_id, string code) {
    Leetcode::getInstance()->checkSolution(this->id, question_id, code);
}

int User::getId() {
    return this->id;
}

string User::getName() {
    return this->name;
}

USER_TYPE User::getUserType() {
    return this->userType;
}
