#include "location.hpp"

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

pair<int, int> Location::getCoordinates() {
    return make_pair(this->x, this->y);
}

void Location::showLocationCoordinates() {
    cout << "Location Details: " << endl;
    cout << this->x << " " << this->y << endl;
}