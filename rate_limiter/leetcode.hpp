#pragma once

#include "question.hpp"
#include "user.hpp"
#include "mutex"

class Leetcode {
    private:
        Leetcode();
        static Leetcode* leetcode;
        static mutex mtx;
        unordered_map<int, User*> users;
        unordered_map<int, Question*> questions;
    public:
       static Leetcode* getInstance();
       User* addUser(int id, string name, USER_TYPE userType);
       Question* addQuestion(int id, string desc);
       void checkSolution(int user_id, int question_id, string code);
};