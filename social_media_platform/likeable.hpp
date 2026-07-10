#pragma once

#include "common.hpp"

class Like;

class Likeable {
    public:
        virtual vector<Like*>& getLikes() = 0;
};