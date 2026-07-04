#include "file.hpp"
#include "editFile.hpp"

File::File(string name, string blob, Folder* parent, User* owner): Component(name,parent, owner) {
    this->blob = blob;
}
string File::getBlob()
{
    return this->blob;
};
EditFile *File::edit(User *user) {
    if (this->checkAccess(user, ACCESS_MODE::EDIT)) {
        return new EditFile(this, user);
    }
    return nullptr;
};
void File::view(User *user)
{
    if (this->checkAccess(user, ACCESS_MODE::VIEW)) {
        cout << "redering contents of the file named " << this->name << " " << this->blob << endl;
    }
};
void File::updateBlob(string blob)
{
    this->blob = blob;
    this->size = blob.size();
    this->updated_at = "22/06/2026";
};