#include "mediaService.hpp"
#include "profile.hpp"
#include "media.hpp"

MediaService *MediaService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new MediaService();
        }
        mtx.unlock();
    }
    return instance;
}

MediaService *MediaService::instance = nullptr;
mutex MediaService::mtx;

MediaService::MediaService()
{
}

string MediaService::save(Media *media)
{
    string blob = media->getBlob();
    string uploadUrl = blob + "adsadsadsadad";
    this->mediaStorage[uploadUrl] = media;
    return uploadUrl;
}
unordered_map<string, Media *> &MediaService::getMediaStorage()
{
    return this->mediaStorage;
}

void MediaService::setMediaStorage(unordered_map<string, Media*>& mediaStorage) {
    this->mediaStorage = mediaStorage;
}