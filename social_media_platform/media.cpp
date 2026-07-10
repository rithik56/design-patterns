#include "media.hpp"

Media::Media(string blob)
{
    this->blob = blob;
}
string Media::getBlob()
{
    return this->blob;
}
void Media::setBlob(string blob)
{
    this->blob = blob;
}