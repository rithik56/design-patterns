#pragma once

#include "common.hpp"
#include "review.hpp"

class Property;
class Rating;
class User;

class PropertyReview: public Review {
    private:
        Property* property;
        User* guest;
    public:
       PropertyReview(int id, Property* property, User* guest, Rating* review);
       User* getReviewer() override;
};