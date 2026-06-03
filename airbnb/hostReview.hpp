#pragma once

#include "common.hpp"
#include "userReview.hpp"
#include "rating.hpp"

class HostReview: public UserReview {
    public:
       HostReview(int id, Host* host, User* user, Rating* rating);
       User* getReviewer() override; 
};