#pragma once

#include "common.hpp"

class FileInput;
class FolderInput;
class File;
class Folder;
class User;

class ComponentFactory {
    private:
        ComponentFactory();
        static ComponentFactory* instance;
        static mutex mtx;
    public:
        static ComponentFactory* getInstance();
        File* createFile(FileInput* input, Folder* parent, User* owner);
        Folder* createFolder(FolderInput* input, Folder* parent, User* owner);
};
