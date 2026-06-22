#pragma once

#include "common.hpp"
#include "editComponent.hpp"

class Folder;

class EditFolder : public EditComponent
{
public:
    EditFolder(Folder *folder, User *user);
    virtual void uploadComponent(Component *component) override;
    virtual Component *createComponent(string name) override;
    virtual void deleteComponent(Component *component) override;
};