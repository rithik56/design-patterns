#pragma once

#include "common.hpp"

class Post;
class Profile;

class FeedService {
    private:
        FeedService();
        static FeedService* instance;
        static mutex mtx;
    public:
        static FeedService* getInstance();
        vector<Post*> generateFeed(Profile* profile);
};