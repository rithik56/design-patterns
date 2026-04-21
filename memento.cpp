#include<iostream>
using namespace std;

class Game {
    private:
        pair<int, int> coords;
    public:
        Game() {
            this->coords.first = 0;
            this->coords.second = 0;
        }
        void setCoords(int x, int y) {
            this->coords.first = x;
            this->coords.second = y;
        }
        void displayCoords() {
            cout << this->coords.first << " " << this->coords.second << endl;
        }
        class Memento {
            private:
                pair<int, int> coords;
                Memento(int x, int y) {
                    this->coords.first = x;
                    this->coords.second = y;
                }
                pair<int, int> getState() {
                    return this->coords;
                }

                friend class Game;
        };
        Game::Memento* createCheckpoint(string name) {
            return new Game::Memento(this->coords.first, this->coords.second);
        }
        void restoreCheckpoint(Game::Memento* m) {
            this->coords = m->getState();
        }
};

class Checkpoint {
    private:
        Game* game;
        unordered_map<string, Game::Memento*> mp;
    public:
        Checkpoint(Game* game) {
            this->game = game;
        }
        void createCheckpoint(string name) {
            Game::Memento* m = game->createCheckpoint(name);
            mp[name] = m;
        }
        void restoreCheckpoint(string name) {
            game->restoreCheckpoint(mp[name]);
        }
};

int main() {
    Game* game = new Game();

    Checkpoint* checkpoint = new Checkpoint(game);
   
    for (int i = 0; i <= 100; i++) {
        game->setCoords(i, i);
        checkpoint->createCheckpoint("checkpoint " + to_string(i));
    }

    // 100 100
    game->displayCoords();

    checkpoint->restoreCheckpoint("checkpoint 34");

    // 34 34
    game->displayCoords();

    return 0;
}