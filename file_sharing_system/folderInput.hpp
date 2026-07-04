#pragma once

#include "common.hpp"
#include "componentInput.hpp"
#include "folder.hpp"

class FolderInput: public ComponentInput {
    private:
        vector<ComponentInput*> inputComponents;
    public:
        FolderInput(string name, vector<ComponentInput*> inputComponents);
        Folder* save(Folder* parent, User* owner) override;
        vector<ComponentInput*>& getInputComponents();
};