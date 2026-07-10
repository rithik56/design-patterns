#pragma once

#include "common.hpp"

class Post;

class Feed {
    private:
        vector<Post*> posts;
    public:
        Feed(vector<Post*> posts);
        vector<Post*>& getPosts();
        void setPosts(vector<Post*>& posts);
};