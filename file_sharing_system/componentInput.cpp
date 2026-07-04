#include "componentInput.hpp"

ComponentInput::ComponentInput(COMPONENT_INPUT inputType, string name)
{
    this->inputType = inputType;
    this->name = name;
}
COMPONENT_INPUT ComponentInput::getInputType()
{
    return this->inputType;
}
double ComponentInput::getSize()
{
    return this->size;
}
string ComponentInput::getName()
{
    return this->name;
}