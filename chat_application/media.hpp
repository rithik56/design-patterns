#pragma once

#include "common.hpp"

class Media {
    protected:
        string url;
    public:
        Media(string url);
        virtual void render() = 0;
};