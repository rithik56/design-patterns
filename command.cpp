#include<iostream>
using namespace std;

class BallController {
    public:
        BallController() {}
        void pass() {
            cout << "pass the ball" << endl;
        }
        void shoot() {
            cout << "shoot the ball" << endl;
        }
        void cross() {
            cout << "cross the ball" << endl;
        }
        void dribble() {
            cout << "dribble the ball" << endl;
        }
};

class Command {
    public:
        virtual void execute() = 0;
};

class BallCommand: public Command {
    protected:
        BallController* ballController;
    public:
        BallCommand(BallController* ballController) {
            this->ballController = ballController;
        }
        virtual void execute() = 0;
};

class PassCommand: public BallCommand {
    public:
        PassCommand(BallController* ballController) : BallCommand(ballController) {
            
        }
        void execute() override {
            this->ballController->pass();
        }
};

class ShootCommand: public BallCommand {
    public:
        ShootCommand(BallController* ballController) : BallCommand(ballController) {
            
        }
        void execute() override {
            this->ballController->shoot();
        }
};

class CrossCommand: public BallCommand {
    public:
        CrossCommand(BallController* ballController) : BallCommand(ballController) {
            
        }
        void execute() override {
            this->ballController->cross();
        }
};

class DribbleCommand: public BallCommand {
    public:
        DribbleCommand(BallController* ballController) : BallCommand(ballController) {
            
        }
        void execute() override {
            this->ballController->dribble();
        }
};

class PlayerController {
    private:
        Command* passCommand;
        Command* shootCommand;
        Command* crossCommand;
        Command* dribbleCommand;
    public:
        PlayerController(Command* passCommand, Command* shootCommand, Command* crossCommand, Command* dribbleCommand) {
            this->passCommand = passCommand;
            this->shootCommand = shootCommand;
            this->crossCommand = crossCommand;
            this->dribbleCommand = dribbleCommand;
        }
        void pass() {
            this->passCommand->execute();
        }
        void shoot() {
            this->shootCommand->execute();
        }
        void cross() {
            this->crossCommand->execute();
        }
        void dribble() {
            this->dribbleCommand->execute();
        }
};

int main() {
    BallController* ballController = new BallController();
    Command* passCommand = new PassCommand(ballController);
    Command* shootCommand = new ShootCommand(ballController);
    Command* crossCommand = new CrossCommand(ballController);
    Command* dribbleCommand = new DribbleCommand(ballController);
    PlayerController* playerController = new PlayerController(passCommand,shootCommand,crossCommand,dribbleCommand);
    playerController->dribble();
    playerController->pass();
    playerController->cross();
    playerController->shoot();
    // dribble the ball
    // pass the ball
    // cross the ball
    // shoot the ball
    return 0;
}


