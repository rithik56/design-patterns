#pragma once

#include "common.hpp"
#include "media.hpp"

class Video: public Media {
    public:
        Video(string url);
        void render() override;
};