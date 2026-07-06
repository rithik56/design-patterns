#include "video.hpp"

Video::Video(string url) : Media(url)
{
}
void Video::render()
{
    cout << "rendering video: " << this->url << endl;
};