#include "feed.hpp"

Feed::Feed(vector<Post *> posts)
{
    this->posts = posts;
}
vector<Post *> &Feed::getPosts()
{
    return this->posts;
}
void Feed::setPosts(vector<Post *> &posts)
{
    this->posts = posts;
}