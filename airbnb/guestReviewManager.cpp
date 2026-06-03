#include "guestReviewManager.hpp"
#include "guestReview.hpp"
#include "user.hpp"

GuestReviewManager* GuestReviewManager::instance = NULL;
mutex GuestReviewManager::mtx;

GuestReviewManager::GuestReviewManager() {

}

GuestReviewManager* GuestReviewManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new GuestReviewManager();
        }
        mtx.unlock();
    }
    return instance;
}

GuestReview* GuestReviewManager::createGuestReview(Host* host, User* user, Rating* rating) {
    int guestReviewId = newGuestReviewId++;
    GuestReview* guestReview = new GuestReview(guestReviewId, host, user, rating);
    this->mp[guestReviewId] = guestReview;
    user->addReview(guestReview);
    return guestReview;
}