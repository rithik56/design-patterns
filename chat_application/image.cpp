#include "image.hpp"

Image::Image(string url) : Media(url)
{
}
void Image::render()
{
    cout << "rendering image: " << this->url << endl;
};