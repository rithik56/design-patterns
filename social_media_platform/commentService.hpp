#pragma once

#include "common.hpp"

class Post;
class Profile;
class Commentable;
class Comment;

class CommentService {
    private:
        CommentService();
        static CommentService* instance;
        static mutex mtx;
        bool checkComment(Commentable* commentable, Comment* comment);
    public:
        static CommentService* getInstance();
        void comment(Commentable* commentable, string description, Profile* createdBy);
        void deleteComment(Commentable* commentable, Comment* comment, Profile* profile);
};