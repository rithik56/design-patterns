#pragma once

#include "common.hpp"
#include "likeable.hpp"
#include "commentable.hpp"

class Profile;
class Like;
class Comment;

class Post: public Likeable, Commentable {
    private:
        int id;
        string description;
        vector<string> urls;
        Profile* createdBy;
        string createdAt;
        vector<Like*> likes;
        vector<Comment*> comments;
    public:
        Post(int id, string description, vector<string> urls, Profile* createdBy);
        int getId();
        string getDescription();
        vector<string>& getUrls();
        Profile* getCreatedBy();
        string getCreatedAt();
        vector<Like*>& getLikes() override;
        vector<Comment*>& getComments() override;
        void setDescription(string description);
        void setUrls(vector<string>& urls);
        void setLikes(vector<Like*>& likes);
        void setComments(vector<Comment*>& comments);
};