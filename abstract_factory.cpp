#include<iostream>
using namespace std;

class Show {
    public:
        virtual void watch() = 0;
};

class Game {
    public:
        virtual void play() = 0;
};

class ChildShow: public Show {
    public:
        ChildShow() {}
        void watch() override {
            cout << "some child show" << endl;
        }
};

class ChildGame: public Game {
    public:
        ChildGame() {}
        void play() override {
            cout << "some child game" << endl;
        }
};

class AdultShow: public Show {
    public:
        AdultShow() {}
        void watch() override {
            cout << "some adult show" << endl;
        }
};

class AdultGame: public Game {
    public:
        AdultGame() {}
        void play() override {
            cout << "some adult game" << endl;
        }
};

class Account {
    public:
        virtual Show* createShow() = 0;
        virtual Game* createGame() = 0;
};

class ChildAccount: public Account {
    public:
        ChildAccount() {

        }
        Show* createShow() override {
            return new ChildShow();
        }
        Game* createGame() override {
            return new ChildGame();
        }
};

class AdultAccount: public Account {
    public:
        AdultAccount() {

        }
        Show* createShow() override {
            return new AdultShow();
        }
        Game* createGame() override {
            return new AdultGame();
        }
};

class Netflix {
    private:
        Account* account;
    public:
        Netflix() {
            this->account = nullptr;
        }
        void setAccount(Account* account) {
            this->account = account;
        }
        void watch() {
            Show* show = account->createShow();
            show->watch();
        }
        void play() {
            Game* game = account->createGame();
            game->play();
        }
};

int main() {
    Netflix* application = new Netflix();
    string accountType = "child";

    Account* account;

    if (accountType == "child") {
        account = new ChildAccount();
    } else {
        account = new AdultAccount();
    }

    application->setAccount(account);

    //some child show
    application->watch();

    // some child game
    application->play();

    return 0;
}