#pragma once

#include "common.hpp"

class Image {
    private:
        string url;
    public:
        Image(string url);
        string getUrl();
        void showImage();
};