#pragma once

#include "common.hpp"
#include "editComponent.hpp"

class Folder;
class ComponentInput;
class File;

class EditFolder : public EditComponent
{
private:
    Folder *folder;
public:
    EditFolder(Folder *folder, User *user);
    Component *createComponent(ComponentInput* input, User* owner);
    // File *createFile(ComponentInput* input, User* owner);
    // Folder *createFolder(ComponentInput* input, User* owner);
    void deleteComponent(Component *component);
    void setName(string name) override;
};