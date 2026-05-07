#include "question.hpp"

Question::Question(int id, string desc) {
    this->id = id;
    this->desc = desc;
}

int Question::getId() {
    return this->id;
}

string Question::getDesc() {
    return this->desc;
}