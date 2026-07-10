#pragma once

#include "common.hpp"

class FriendRequest;
class Post;
class Feed;

class Profile {
    private:
        int id;
        string name;
        string email;
        string password;
        vector<Post*> posts;
        vector<FriendRequest*> friendRequests;
        string lastSeen;
        vector<Profile*> friends;
        Feed* feed;
    public:
        Profile(int id, string name, string email, string password);
        int getId();
        string getName();
        string getEmail();
        string getPassword();
        vector<Post*>& getPosts();
        vector<FriendRequest*>& getFriendRequests();
        string getLastSeen();
        vector<Profile*>& getFriends();
        Feed* getFeed();
        void setEmail(string email);
        void setPassword(string password);
        void setPosts(vector<Post*>& posts);
        void setFriendRequests(vector<FriendRequest*>& friendRequests);
        void setLastSeen(string lastSeen);
        void setFriends(vector<Profile*>& friends);
        void setFeed(Feed* feed);
};