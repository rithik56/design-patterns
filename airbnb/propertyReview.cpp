#include "propertyReview.hpp"

PropertyReview::PropertyReview(int id, Property* property, User* guest, Rating* rating) : Review(id, rating)
{
    this->property = property;
    this->guest = guest;
}

User* PropertyReview::getReviewer() {
    return this->guest;
}

