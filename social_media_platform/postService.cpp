#include "postService.hpp"
#include "post.hpp"
#include "mediaService.hpp"
#include "profile.hpp"
#include "feed.hpp"

PostService *PostService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new PostService();
        }
        mtx.unlock();
    }
    return instance;
}

PostService *PostService::instance = nullptr;
mutex PostService::mtx;

PostService::PostService()
{
}

void PostService::createPost(string description, vector<Media*> media, Profile *createdBy)
{
    vector<string> urls = this->uploadMedia(media);
    Post *post = new Post(postId++, description, urls, createdBy);
    createdBy->getPosts().push_back(post);
    vector<Profile *> friends = createdBy->getFriends();
    for (int i = 0; i < friends.size(); i++)
    {
        friends[i]->getFeed()->getPosts().push_back(post);
    }
}

void PostService::deletePost(Post *post, Profile *profile)
{
    if (post->getCreatedBy() != profile) {
        cout << "this is not the original author of the post. Hence this operation is not allowed" << endl;
        return;
    }
    auto it = find(profile->getPosts().begin(), profile->getPosts().end(), post);
    profile->getPosts().erase(it);
    vector<Profile *> friends = profile->getFriends();
    for (int i = 0; i < friends.size(); i++)
    {
        auto it = find(friends[i]->getFeed()->getPosts().begin(), friends[i]->getFeed()->getPosts().end(), post);
        friends[i]->getFeed()->getPosts().erase(it);
    }
}

vector<string> PostService::uploadMedia(vector<Media*> media)
{
    vector<string> urls;
    for (int i = 0; i < media.size(); i++)
    {
        string url = MediaService::getInstance()->save(media[i]);
        urls.push_back(url);
    }
    return urls;
}