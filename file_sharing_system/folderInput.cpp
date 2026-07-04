#include "folderInput.hpp"
#include "componentFactory.hpp"

FolderInput::FolderInput(string name, vector<ComponentInput *> inputComponents): ComponentInput(COMPONENT_INPUT::FOLDER_INPUT, name)
{
    double size = 0;
    for (int i = 0; i < inputComponents.size(); i++) {
        size += inputComponents[i]->getSize();
    }
    this->size = size;
    this->inputComponents = inputComponents;
}

vector<ComponentInput *> &FolderInput::getInputComponents()
{
    return this->inputComponents;
}

Folder* FolderInput::save(Folder* parent, User* owner) {
    Folder* folder = ComponentFactory::getInstance()->createFolder(this, parent, owner);
    return folder;
};