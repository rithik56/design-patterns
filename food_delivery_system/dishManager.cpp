#include "dishManager.hpp"

DishManager* DishManager::instance = NULL;
mutex DishManager::mtx;

DishManager::DishManager() {

}

DishManager* DishManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new DishManager();
        }
        mtx.unlock();
    }
    return instance;
}

Dish* DishManager::addDish(string name, double price) {
    int dishId = newDishId++;
    Dish* dish = new Dish(dishId, name, price);
    this->mp[dishId] = dish; 
    return dish;
}