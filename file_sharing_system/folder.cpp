#include "folder.hpp"
#include "file.hpp"
#include "component.hpp"
#include "accessList.hpp"
#include "user.hpp"
#include "editFolder.hpp"
#include "fileInput.hpp"

Folder::Folder(string name, vector<Component *> components, Folder *parent, User *owner) : Component(name, parent, owner)
{
    this->components = components;
}
Component *Folder::createComponent(ComponentInput *input, User *owner)
{
    if (!this->checkNameConflict(input->getName()) && !this->checkSizeConflict(input))
    {
        Component *component = input->save(this, owner);
        this->addComponent(component, input->getSize());
        return component;
    }
    return nullptr;
}
void Folder::deleteComponent(Component *component)
{
    auto it = find(this->components.begin(), this->components.end(), component);
    component->updateSize(-1 * component->getSize());
    this->components.erase(it);
}
void Folder::view(User *user)
{
    if (this->checkAccess(user, ACCESS_MODE::VIEW))
    {
        for (int i = 0; i < this->components.size(); i++)
        {
            cout << this->components[i]->getName() << endl;
        }
    }
}
EditFolder *Folder::edit(User *user)
{
    if (this->checkAccess(user, ACCESS_MODE::EDIT))
    {
        return new EditFolder(this, user);
    }
    return nullptr;
};
bool Folder::checkNameConflict(string name)
{
    for (int i = 0; i < this->components.size(); i++)
    {
        if (this->components[i]->getName() == name)
        {
            cout << "a file or folder already exists with this name. choose another name" << endl;
            return true;
        }
    }
    return false;
}
void Folder::updateFile(File *file, string blob)
{
    double remainingLimit = this->accessList->getOwner()->getAvailableLimit();
    double currDiff = blob.size() - file->getSize();
    if (remainingLimit >= currDiff)
    {
        file->updateBlob(blob);
        file->updateSize(currDiff);
    }
    else
    {
        cout << "Sorry. you do not have enough storage to edit this file. Please make the size of file smaller" << endl;
    }
}
void Folder::updateComponentName(Component *component, string name)
{
    if (!this->checkNameConflict(name))
    {
        this->setName(name);
    }
}
bool Folder::checkSizeConflict(ComponentInput *input)
{
    double remainingLimit = this->accessList->getOwner()->getAvailableLimit();
    if (remainingLimit >= input->getSize())
    {
        return false;
    }
    cout << "you can't save the component as you are out of storage." << endl;
    return true;
}
unordered_set<Component *> &Folder::getSharedComponents()
{
    return this->sharedComponents;
}
void Folder::addSharedComponent(Component *component)
{
    this->sharedComponents.insert(component);
}
void Folder::addComponent(Component* component, double size) {
    this->components.push_back(component);
    component->updateSize(size);
}