#include "restaurantManager.hpp"

RestaurantManager* RestaurantManager::instance = NULL;
mutex RestaurantManager::mtx;

RestaurantManager::RestaurantManager() {

}

RestaurantManager* RestaurantManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new RestaurantManager();
        }
        mtx.unlock();
    }
    return instance;
}

Restaurant* RestaurantManager::addRestaurant(string name, string phone, Location* location) {
    int restaurantId = newRestaurantId++;
    Restaurant* restaurant = new Restaurant(restaurantId, name, phone, location);
    this->mp[restaurantId] = restaurant; 
    return restaurant;
}