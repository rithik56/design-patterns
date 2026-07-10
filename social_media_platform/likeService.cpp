#include "likeService.hpp"
#include "profile.hpp"
#include "likeable.hpp"
#include "like.hpp"

LikeService *LikeService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new LikeService();
        }
        mtx.unlock();
    }
    return instance;
}

LikeService *LikeService::instance = nullptr;
mutex LikeService::mtx;

LikeService::LikeService()
{
}

void LikeService::like(Likeable *likeable, Profile *createdBy)
{
    Like* like = checkLike(likeable, createdBy);
    if (like)
    {
        cout << "already liked by the user" << endl;
        return;
    }
    likeable->getLikes().push_back(new Like(likeId, createdBy));
}
void LikeService::unlike(Likeable *likeable, Profile *createdBy)
{
    Like* like = checkLike(likeable, createdBy);
    if (!like)
    {
        cout << "like not present" << endl;
        return;
    }
    auto it = find(likeable->getLikes().begin(), likeable->getLikes().end(), like);
    likeable->getLikes().erase(it);
}
Like* LikeService::checkLike(Likeable *likeable, Profile *profile)
{
    vector<Like *> likes = likeable->getLikes();
    for (int i = 0; i < likes.size(); i++)
    {
        if (likes[i]->getCreatedBy() == profile)
        {
            return likes[i];
        }
    }
    return NULL;
}