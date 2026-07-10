#include "commentService.hpp"
#include "profile.hpp"
#include "commentable.hpp"
#include "comment.hpp"

CommentService *CommentService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new CommentService();
        }
        mtx.unlock();
    }
    return instance;
}

CommentService *CommentService::instance = nullptr;
mutex CommentService::mtx;

CommentService::CommentService()
{
}

void CommentService::comment(Commentable *commentable, string description, Profile *createdBy)
{
    commentable->getComments().push_back(new Comment(commentId++, description, createdBy));
}
void CommentService::deleteComment(Commentable *commentable, Comment* comment, Profile *profile)
{
    if (comment->getCreatedBy() != profile) {
        cout << "you are not the original author, unable to delete" << endl;
        return;
    }
    bool isCommentPresent = checkComment(commentable, comment);
    if (!comment)
    {
        cout << "comment already deleted" << endl;
        return;
    }
    auto it = find(commentable->getComments().begin(), commentable->getComments().end(), comment);
    commentable->getComments().erase(it);
}
bool CommentService::checkComment(Commentable *commentable, Comment* comment)
{
    vector<Comment *> comments = commentable->getComments();
    for (int i = 0; i < comments.size(); i++)
    {
        if (comments[i] == comment)
        {
            return true;
        }
    }
    return false;
}