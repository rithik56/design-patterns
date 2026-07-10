#pragma once

#include "common.hpp"

class Post;
class Profile;
class Likeable;
class Like;

class LikeService {
    private:
        LikeService();
        static LikeService* instance;
        static mutex mtx;
        Like* checkLike(Likeable* likeable, Profile* profile);
    public:
        static LikeService* getInstance();
        void like(Likeable* likeable, Profile* createdBy);
        void unlike(Likeable* likeable, Profile* createdBy);
};