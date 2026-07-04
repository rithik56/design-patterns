#include "editFile.hpp"
#include "file.hpp"
#include "storageService.hpp"
#include "user.hpp"
#include "plan.hpp"
#include "accessList.hpp"
#include "folder.hpp"

EditFile::EditFile(File *file, User *user) : EditComponent(user, file->getAccessList(), file->getParent())
{
    this->file = file;
}
void EditFile::updateComponent(string blob)
{
    if (this->checkAccess()) {
        this->parent->updateFile(this->file, blob);
    }
}

void EditFile::setName(string name) {
    if (this->checkAccess()) {
        this->parent->updateComponentName(this->file, name);
    }
}
