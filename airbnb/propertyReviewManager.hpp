#pragma once

#include "common.hpp"
#include "mutex"

class PropertyReview;
class Rating;
class Property;
class User;

class PropertyReviewManager {
    private:
        PropertyReviewManager();
        static PropertyReviewManager* instance;
        static mutex mtx;
        unordered_map<int, PropertyReview*> mp;
    public:
        static PropertyReviewManager* getInstance();
        PropertyReview* createPropertyReview(Property* property, User* guest, Rating* review);
};