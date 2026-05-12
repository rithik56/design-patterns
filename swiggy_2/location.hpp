#pragma once

#include "common.hpp"

class Location {
    private:
        int x;
        int y;
    public:
        Location(int x, int y);
        std::pair<int, int> getLocation();
};