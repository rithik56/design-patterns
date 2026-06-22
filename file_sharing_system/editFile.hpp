#pragma once

#include "common.hpp"
#include "editComponent.hpp"

class File;
class User;

class EditFile: public EditComponent {
    public:
        EditFile(File* file, User* user);
        void updateComponent(string blob) override;
};