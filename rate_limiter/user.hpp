#pragma once

#include "common.hpp"

class User {
    private:
        int id;
        string name;
        USER_TYPE userType;
    public:
        User(int id, string name, USER_TYPE userType);
        void submitSolution(int question_id, string code);
        int getId();
        string getName();
        USER_TYPE getUserType();
};