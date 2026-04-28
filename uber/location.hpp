#pragma once

#include "common.hpp"

class Location {
    private:
        int latitude;
        int longitude;
    public:
        Location(int latitude, int longitude);
        int getLatitude();
        int getLongitude();
};