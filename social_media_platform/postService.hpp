#pragma once

#include "common.hpp"

class Media;
class Profile;
class Post;

class PostService {
    private:
        PostService();
        static PostService* instance;
        static mutex mtx;
        vector<string> uploadMedia(vector<Media*> media);
    public:
        static PostService* getInstance();
        void createPost(string description, vector<Media*> media, Profile* createdBy);
        void deletePost(Post* post, Profile* profile);
};