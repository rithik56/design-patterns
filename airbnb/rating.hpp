#pragma once

#include "common.hpp"

class Rating {
    private:
        double rating;
        string review;
    public:
        Rating(double rating, string review);
        double getRating();
        string getReview();
        void show();
};