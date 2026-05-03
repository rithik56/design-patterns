#include "location.hpp"

Location::Location(int latitude, int longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
}

int Location::getLatitude() {
    return this->latitude;
}

int Location::getLongitude() {
    return this->longitude;
}