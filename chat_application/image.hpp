#pragma once

#include "common.hpp"
#include "media.hpp"

class Image: public Media {
    public:
        Image(string url);
        void render() override;
};