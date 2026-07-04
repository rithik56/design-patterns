#include "fileInput.hpp"
#include "componentFactory.hpp"

FileInput::FileInput(string name, string blob) : ComponentInput(COMPONENT_INPUT::FILE_INPUT, name)
{
    this->blob = blob;
    this->size = blob.size();
}

string FileInput::getBlob()
{
    return this->blob;
}

File* FileInput::save(Folder* parent, User* owner) {
    File* file = ComponentFactory::getInstance()->createFile(this, parent, owner);
    return file;
};