#pragma once

#include "common.hpp"
#include "userReview.hpp"

class Rating;
class Host;
class User;

class GuestReview: public UserReview {
    public:
       GuestReview(int id, Host* host, User* user, Rating* rating);
       User* getReviewer() override; 
};