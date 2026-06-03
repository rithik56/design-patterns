#include "guestReview.hpp"

GuestReview::GuestReview(int id, Host *host, User *user, Rating *rating) : UserReview(id, host, user, rating)
{
}
User *GuestReview::getReviewer() {
    return this->user;
};