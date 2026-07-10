#include "profileService.hpp"
#include "friendRequestService.hpp"
#include "postService.hpp"
#include "friendRequest.hpp"
#include "profile.hpp"
#include "feed.hpp"
#include "feedService.hpp"
#include "likeService.hpp"
#include "commentService.hpp"
#include "like.hpp"
#include "likeable.hpp"
#include "post.hpp"

int main() {
    ProfileService* profileService = ProfileService::getInstance();
    FriendRequestService* friendRequestService = FriendRequestService::getInstance();
    PostService* postService = PostService::getInstance();
    FeedService* feedService = FeedService::getInstance();
    LikeService* likeService = LikeService::getInstance();
    CommentService* commentService = CommentService::getInstance();
    Profile* profile1 = profileService->createProfile("rithik19901998@gmail.com", "abcdef", "Rithik");
    // this email already exists in DB. Use another email.
    Profile* profile2 = profileService->createProfile("rithik19901998@gmail.com", "abcdef", "Rithik");
    profile2 = profileService->createProfile("rahul19901998@gmail.com", "abcdef", "Rahul");
    FriendRequest* request1 = friendRequestService->createFriendRequest(profile1, profile2);
    // Friend request already sent to this user.
    FriendRequest* request2 = friendRequestService->createFriendRequest(profile1, profile2);
    // 1
    cout << profile2->getFriendRequests().size() << endl;
    friendRequestService->acceptFriendRequest(profile2, profile2->getFriendRequests()[0]);
    // 1
    cout << profile1->getFriends().size() << endl;
    // 1
    cout << profile2->getFriends().size() << endl;
    postService->createPost("Hey Guys. I am in New York! Lets's catch up", {}, profile1);
    // 1
    cout << profile1->getPosts().size() << endl;
    vector<Post*> profile2FeedPosts = profile2->getFeed()->getPosts();
    // 1
    cout << profile2FeedPosts.size() << endl;
    likeService->like((Likeable*)profile2FeedPosts[0], profile2);
    // already liked by the user
    likeService->like((Likeable*)profile2FeedPosts[0], profile2);
    commentService->comment((Commentable*)profile2FeedPosts[0], "sure let's catch up", profile2);
    commentService->comment((Commentable*)profile2FeedPosts[0], "let's connect over dm", profile2);
    // 1
    cout << profile1->getPosts()[0]->getLikes().size() << endl;
    // 2
    cout << profile1->getPosts()[0]->getComments().size() << endl;
    likeService->unlike((Likeable*)profile2FeedPosts[0], profile2);
    commentService->deleteComment((Commentable*)profile2FeedPosts[0], profile1->getPosts()[0]->getComments()[0], profile2);
    // 0
    cout << profile1->getPosts()[0]->getLikes().size() << endl;
    // 1
    cout << profile1->getPosts()[0]->getComments().size() << endl;
    return 0;
}