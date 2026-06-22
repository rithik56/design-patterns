#include "folder.hpp"
#include "file.hpp"
#include "component.hpp"

Folder::Folder(string name): Component(name)
{

}
File *Folder::createFile(string name, double size, string blob)
{
    File* file = new File(name, size, blob);
    this->components.push_back(file);
    return file;
}
void Folder::uploadFile(File *file)
{
    this->components.push_back(file);
}
Folder *Folder::createFolder(string name)
{
    Folder* folder = new Folder(name);
    this->components.push_back(folder);
}
void Folder::Folder::uploadFolder(Folder *folder)
{
    this->components.push_back(folder);
}
void Folder::deleteComponent(Component *component)
{
    auto it = find(this->components.begin(), this->components.end(), component);
    this->components.erase(it);
}
void Folder::view() {
    for (int i = 0; i < this->components.size(); i++) {
        cout << this->components[i]->getName() << endl;
    }
}