#include "propertyReviewManager.hpp"
#include "propertyReview.hpp"
#include "property.hpp"

PropertyReviewManager* PropertyReviewManager::instance = NULL;
mutex PropertyReviewManager::mtx;

PropertyReviewManager::PropertyReviewManager() {

}

PropertyReviewManager* PropertyReviewManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new PropertyReviewManager();
        }
        mtx.unlock();
    }
    return instance;
}

PropertyReview* PropertyReviewManager::createPropertyReview(Property* property, User* guest, Rating* review) {
    int propertyReviewId = newPropertyReviewId++;
    PropertyReview* propertyReview = new PropertyReview(propertyReviewId, property, guest, review);
    this->mp[propertyReviewId] = propertyReview;
    property->addReview(propertyReview);
    return propertyReview;
}