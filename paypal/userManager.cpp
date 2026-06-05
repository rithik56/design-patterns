#include "userManager.hpp"
#include "user.hpp"

UserManager* UserManager::instance = NULL;
mutex UserManager::mtx;

UserManager::UserManager() {

}

UserManager* UserManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new UserManager();
        }
        mtx.unlock();
    }
    return instance;
}

User* UserManager::addUser(string name, string email) {
    int userId = newUserId++;
    User* user = new User(userId, name, email);
    this->mp[userId] = user; 
    return user;
}