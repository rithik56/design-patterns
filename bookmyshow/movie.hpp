#pragma once

#include<iostream>
using namespace std;

class Movie {
    private:
        int id;
        int duration;
        string title;
        string language;
    public:
        Movie(int id, int duration, string title, string language);
        int getId();
        int getDuration();
        string getTitle();
        string getLanguage();
};
