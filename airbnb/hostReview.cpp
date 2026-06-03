#include "hostReview.hpp"

HostReview::HostReview(int id, Host *host, User *user, Rating *rating) : UserReview(id, host, user, rating)
{
}
User *HostReview::getReviewer() {
    return this->user;
};