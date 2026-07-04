#include "componentFactory.hpp"
#include "file.hpp"
#include "folder.hpp"
#include "fileInput.hpp"
#include "folderInput.hpp"

ComponentFactory *ComponentFactory::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new ComponentFactory();
        }
        mtx.unlock();
    }
    return instance;
}

ComponentFactory *ComponentFactory::instance = nullptr;
mutex ComponentFactory::mtx;

ComponentFactory::ComponentFactory()
{
}

File* ComponentFactory::createFile(FileInput* input, Folder* parent, User* owner) {
    File* file = new File(input->getName(), input->getBlob(), parent, owner);
    return file;
}

Folder* ComponentFactory::createFolder(FolderInput* input, Folder* parent, User* owner) {
    Folder* folder = new Folder(input->getName(), {}, parent, owner);
    for (int i = 0; i < input->getInputComponents().size(); i++) {
        Component* c = input->getInputComponents()[i]->save(folder, owner);
    }
    return folder;
}