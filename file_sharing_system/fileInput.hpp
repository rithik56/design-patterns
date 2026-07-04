#pragma once

#include "common.hpp"
#include "componentInput.hpp"
#include "file.hpp"

class File;

class FileInput: public ComponentInput {
    private:
        string blob;
    public:
        FileInput(string name, string blob);
        File* save(Folder* parent, User* owner) override;
        string getBlob();
};