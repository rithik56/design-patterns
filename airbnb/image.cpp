#include "image.hpp"

Image::Image(string url)
{
    this->url = url;
}
string Image::getUrl()
{
    return this->url;
}
void Image::showImage()
{
    cout << "image url: " << this->url << endl;
}