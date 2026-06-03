#pragma once

#include "common.hpp"
#include "review.hpp"

class Host;
class User;
class Rating;

class UserReview: public Review {
    protected:
        Host* host;
        User* user;
    public:
        UserReview(int id, Host* host, User* user, Rating* rating);
        Host* getHost();
        User* getUser();
        Rating* getRating();
        virtual User* getReviewer() = 0;
};