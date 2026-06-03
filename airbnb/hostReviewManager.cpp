#include "hostReviewManager.hpp"
#include "hostReview.hpp"
#include "host.hpp"

HostReviewManager* HostReviewManager::instance = NULL;
mutex HostReviewManager::mtx;

HostReviewManager::HostReviewManager() {

}

HostReviewManager* HostReviewManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new HostReviewManager();
        }
        mtx.unlock();
    }
    return instance;
}

HostReview* HostReviewManager::createHostReview(Host* host, User* user, Rating* rating) {
    int hostReviewId = newHostReviewId++;
    HostReview* hostReview = new HostReview(hostReviewId, host, user, rating);
    this->mp[hostReviewId] = hostReview;
    host->addReview(hostReview);
    return hostReview;
}