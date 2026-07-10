#pragma once

#include "common.hpp"

class Profile;

class Comment {
    private:
        int id;
        string description;
        Profile* createdBy;
        string createdAt;
    public:
        Comment(int id, string description, Profile* createdBy);
        int getId();
        string getDescription();
        Profile* getCreatedBy();
        string getCreatedAt();
        void setDescription(string description);
};