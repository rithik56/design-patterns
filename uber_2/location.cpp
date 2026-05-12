#include "location.hpp"

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

pair<int,int> Location::getLocation() {
    return make_pair(this->x, this->y);
}