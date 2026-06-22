#pragma once

#include "common.hpp"
#include "component.hpp"

class File: public Component {
    private:
        string blob;
    public:
        File(string name);
        void view() override;
};