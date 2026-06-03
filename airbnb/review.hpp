#pragma once

#include "common.hpp"

class User;
class Rating;

class Review {
    protected:
        int id;
        Rating* rating;
    public:
        Review(int id, Rating* rating);
        virtual User* getReviewer() = 0;
        void showReview();
};