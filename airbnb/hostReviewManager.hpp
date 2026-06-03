#pragma once

#include "common.hpp"
#include "mutex"

class HostReview;
class Rating;
class User;
class Host;

class HostReviewManager {
    private:
        HostReviewManager();
        static HostReviewManager* instance;
        static mutex mtx;
        unordered_map<int, HostReview*> mp;
    public:
        static HostReviewManager* getInstance();
        HostReview* createHostReview(Host* host, User* user, Rating* rating);
};