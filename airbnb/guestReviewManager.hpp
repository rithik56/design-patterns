#pragma once

#include "common.hpp"
#include "mutex"

class GuestReview;
class Rating;
class Host;
class User;

class GuestReviewManager {
    private:
        GuestReviewManager();
        static GuestReviewManager* instance;
        static mutex mtx;
        unordered_map<int, GuestReview*> mp;
    public:
        static GuestReviewManager* getInstance();
        GuestReview* createGuestReview(Host* host, User* user, Rating* rating);
};