#include "editFolder.hpp"
#include "folder.hpp"

EditFolder::EditFolder(Folder *folder, User *user) : EditComponent(user, folder->getAccessList(), folder->getParent())
{
    this->folder = folder;
}
Component *EditFolder::createComponent(ComponentInput* input, User* owner) {
    if (this->checkAccess()) {
        return this->folder->createComponent(input, user);
    }
    return nullptr;
}
void EditFolder::deleteComponent(Component *component)
{
    if (this->checkAccess())
    {
        this->folder->deleteComponent(component);
    }
}
void EditFolder::setName(string name)
{
    if (this->checkAccess())
    {
        this->parent->updateComponentName(this->folder, name);
    }
};