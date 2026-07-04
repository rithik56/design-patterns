#include "storageService.hpp"
#include "user.hpp"
#include "folder.hpp"
#include "plan.hpp"

StorageService *StorageService::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new StorageService();
        }
        mtx.unlock();
    }
    return instance;
}

StorageService *StorageService::instance = nullptr;
mutex StorageService::mtx;

StorageService::StorageService()
{
}

User* StorageService::createDirectory(string name, string email, Plan* plan) {
    User* user = new User(userId, name, email, plan);
    Folder* component = new Folder("home", {}, NULL, user);
    this->homeDirectories[user] = component;
    return user;
}

Folder* StorageService::getDirectory(User* user) {
    return this->homeDirectories[user];
}

double StorageService::getDirectorySize(User* user) {
    return this->homeDirectories[user]->getSize();
}