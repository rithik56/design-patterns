#pragma once

#include "common.hpp"
#include "component.hpp"
#include "unordered_set"
#include "editFolder.hpp"

class File;
class User;
class ComponentInput;

class Folder: public Component {
    private:
        vector<Component*> components;
        unordered_set<Component*> sharedComponents;
        void updateFile(File* file, string blob);
        Component* createComponent(ComponentInput* input, User* owner);
        void addComponent(Component* component, double size);
        void deleteComponent(Component* component);
        bool checkNameConflict(string name);
        bool checkSizeConflict(ComponentInput *input);
        void updateComponentName(Component* component, string name);
        void addSharedComponent(Component* component);
    public:
        friend class EditFolder;
        friend class EditFile;
        friend class LinkService;
        friend class ComponentFactory;
        Folder(string name, vector<Component*> components, Folder* parent, User* owner);
        void view(User* user) override;
        EditFolder* edit(User* user) override;
        unordered_set<Component*>& getSharedComponents();
};