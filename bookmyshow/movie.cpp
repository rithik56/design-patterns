#include "movie.hpp"

Movie::Movie(int id, int duration, string title, string language)
{
    this->id = id;
    this->duration = duration;
    this->title = title;
    this->language = language;
}

int Movie::getId()
{
    return this->id;
}

int Movie::getDuration()
{
    return this->duration;
}

string Movie::getTitle()
{
    return this->title;
}

string Movie::getLanguage()
{
    return this->language;
}