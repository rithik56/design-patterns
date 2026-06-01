#include "theater.hpp"
#include "screen.hpp"
#include "show.hpp"

#include<set>

Theater::Theater(int id, string name, Location *location)
{
    this->id = id;
    this->name = name;
    this->location = location;
}
void Theater::addScreen(int rows, int numberOfSeatsPerRow, unordered_map<int, pair<SEAT_CATEGORY, int>> customizedSeats)
{
    int id = this->screens.size();
    Screen *screen = new Screen(id, this, rows, numberOfSeatsPerRow, customizedSeats);
    this->screens.push_back(screen);
}

void Theater::displayMovieTimings(Movie *movie, string date)
{
    cout << "Movie " << movie->getTitle() << ":" << endl;
    for (auto it = this->schedule.begin(); it != this->schedule.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i]->getMovie() == movie) {
                cout << it->second[i]->getStartTiming() << " ";
            }
        }
    }
    cout << endl;
}

void Theater::displayShowTimings(string date)
{
    for (auto it = this->movies.begin(); it != this->movies.end(); it++) {
        displayMovieTimings(it->first, date);
    }
}

Show* Theater::addShow(Movie *movie, string date, string startTiming, int duration, int screenId, unordered_map<SEAT_CATEGORY, int> seatPrice) {
    int id = this->schedule.find(screenId) == this->schedule.end() ? 0 : this->schedule[screenId].size();
    Screen* screen = this->getFreshScreen(screenId);
    Show* show = new Show(id, movie, startTiming, duration, screen, seatPrice);
    this->schedule[screenId].push_back(show);
    this->movies[movie]++;
    return show;
}

Screen* Theater::getFreshScreen(int screenId) {
    return this->screens[screenId]->clone();
}

 Location* Theater::getLocation() {
    return this->location;
 }

 string Theater::getName() {
    return this->name;
 }

  int Theater::getId() {
    return this->id;
 }