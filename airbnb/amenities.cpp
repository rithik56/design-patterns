#include "amenities.hpp"

Amenities::Amenities(string benefit, string icon)
{
    this->benefit = benefit;
    this->icon = icon;
}
void Amenities::show()
{
    cout << "Amenity: " << endl;
    cout << "Icon: " << this->icon << endl;
    cout << "Benefit: " << this->benefit << endl;
}