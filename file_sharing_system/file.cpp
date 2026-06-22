#include "file.hpp"

File::File(string name): Component(name)
{
    this->blob = "";
}
void File::view()
{
    cout << "redering contents of the file named " << this->name << " " << this->blob << endl;
}