#include "location.hpp"

Location::Location(int x, int y)
{
    this->x = x;
    this->y = y;
}
std::pair<int, int> Location::getLocation()
{
    return make_pair(this->x, this->y);
}