#pragma once

#include "common.hpp"

class Component;
class Folder;
class User;

class ComponentInput {
    protected:
        COMPONENT_INPUT inputType;
        string name;
        double size;
    public:
        ComponentInput(COMPONENT_INPUT inputType, string name);
        COMPONENT_INPUT getInputType();
        double getSize();
        string getName();
        virtual Component* save(Folder* parent, User* owner) = 0;
};