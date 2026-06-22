#pragma once

#include "common.hpp"
#include "component.hpp"

class File;

class Folder: public Component {
    private:
        vector<Component*> components;
    public:
        Folder(string name);
        File* createFile(string name, double size, string blob);
        void uploadFile(File* file);
        Folder* createFolder(string name);
        void uploadFolder(Folder* folder);
        void deleteComponent(Component* component);
        void view() override;
};