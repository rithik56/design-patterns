#include "editFile.hpp"
EditFile::EditFile(File *file, User *user): EditComponent(user, file)
{
}
void EditFile::updateComponent(string blob)
{
    // check if the updated file fits within the folder constraints in which the file resides
    // get Home directory size

}