#pragma once

#include "common.hpp"

class Question {
    private:
        int id;
        string desc;
    public:
        Question(int id, string desc);
        int getId();
        string getDesc();
};