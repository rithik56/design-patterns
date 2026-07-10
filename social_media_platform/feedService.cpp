#include "feedService.hpp"
#include "profile.hpp"
#include "feed.hpp"

FeedService *FeedService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new FeedService();
        }
        mtx.unlock();
    }
    return instance;
}

FeedService *FeedService::instance = nullptr;
mutex FeedService::mtx;

FeedService::FeedService()
{
}

vector<Post*> FeedService::generateFeed(Profile* profile) {
    profile->setFeed({});
    return profile->getFeed()->getPosts();
}