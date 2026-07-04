#pragma once

#include "common.hpp"

class User;
class Folder;
class Plan;

class StorageService {
    private:
        unordered_map<User*, Folder*> homeDirectories;
        StorageService();
        static StorageService* instance;
        static mutex mtx;
    public:
        static StorageService* getInstance();
        User* createDirectory(string name, string email, Plan* plan);
        Folder* getDirectory(User* user);
        double getDirectorySize(User* user);
};