#pragma once

#include "common.hpp"

class Profile;

class Like {
    private:
        int id;
        Profile* createdBy;
    public:
        Like(int id, Profile* createdBy);
        int getId();
        Profile* getCreatedBy();
};