#pragma once

#include "common.hpp"

class Comment;

class Commentable {
    public:
        virtual vector<Comment*>& getComments() = 0;
};