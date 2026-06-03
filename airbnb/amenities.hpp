#pragma once

#include "common.hpp"

class Amenities {
    private:
        string benefit;
        string icon;
    public:
        Amenities(string benefit, string icon);
        void show();
};