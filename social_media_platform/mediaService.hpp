#pragma once

#include "common.hpp"

class Media;
class Profile;
class Post;

class MediaService {
    private:
        MediaService();
        unordered_map<string, Media*> mediaStorage;
        static MediaService* instance;
        static mutex mtx;
    public:
        static MediaService* getInstance();
        string save(Media* media);
        unordered_map<string, Media*>& getMediaStorage();
        void setMediaStorage(unordered_map<string, Media*>& mediaStorage);
};