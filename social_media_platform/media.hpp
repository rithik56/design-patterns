#pragma once

#include "common.hpp"

class Media {
    private:    
        string blob;
    public:
        Media(string blob);
        string getBlob();
        void setBlob(string blob);
};