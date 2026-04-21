#include<iostream>
using namespace std;

class Player;

class Mediator {
    public:
        virtual void notify(Player* player, string event) = 0;
};

class Player {
    private:
        Mediator* m;
    public:
        Player(Mediator* m) {
            this->m = m;
        }
        void pass() {
            m->notify(this, "pass");
        }
};

class Game: public Mediator {
    private:
        Player* player1;
        Player* player2;
        Player* player3;
        Player* player4;
        Player* player5;
    public:
        Game() {
            this->player1 = nullptr;
            this->player2 = nullptr;
            this->player3 = nullptr;
            this->player4 = nullptr;
            this->player5 = nullptr;
        }
        void setPlayers(Player* player1, Player* player2, Player* player3, Player* player4, Player* player5) {
            this->player1 = player1;
            this->player2 = player2;
            this->player3 = player3;
            this->player4 = player4;
            this->player5 = player5;
        }
        void notify(Player* player, string event) override {
            if (player == this->player1) {
                if (event == "pass") {
                    cout << "handle player1 pass" << endl;
                }
            } else if (player == this->player2) {
                if (event == "pass") {
                    cout << "handle player2 pass" << endl;
                }
            }
        }
};

int main() {
    Game* game = new Game();
    Player* player1 = new Player(game);
    Player* player2 = new Player(game);
    Player* player3 = new Player(game);
    Player* player4 = new Player(game);
    Player* player5 = new Player(game);

    game->setPlayers(player1, player2, player3, player4, player5);

    player1->pass();
    player2->pass();

    return 0;
}
