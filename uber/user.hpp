#pragma once

#include "common.hpp"
#include "location.hpp"

class User {
    protected:
        string id;
        string name;
        string phone;
    public:
        User(string id, string name, string phone);
        string getId();
        string getName();
};