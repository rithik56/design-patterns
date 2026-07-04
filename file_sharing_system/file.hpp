#pragma once

#include "common.hpp"
#include "component.hpp"
#include "editFile.hpp"

class User;

class File: public Component {
    private:
        string blob;
        void updateBlob(string blob);
    public:
        friend class EditFile;
        friend class Folder;
        File(string name, string blob, Folder* parent, User* owner);
        string getBlob();
        EditFile* edit(User* user) override;
        void view(User* user) override;
};