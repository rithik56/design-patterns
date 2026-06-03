#include "userReview.hpp"

UserReview::UserReview(int id, Host *host, User *user, Rating *rating): Review(id, rating)
{
    this->host = host;
    this->user = user;
}
Host *UserReview::getHost()
{
    return this->host;
}
User *UserReview::getUser()
{
    return this->user;
}
Rating *UserReview::getRating()
{
    return this->rating;
}