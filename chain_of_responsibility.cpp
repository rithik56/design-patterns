#include<iostream>
using namespace std;

class Handler {
    public:
        virtual void setNext(Handler* h) = 0;
        virtual void onClickHandler() = 0;
};

class BaseHandler: public Handler {
    protected:
        Handler* next;
        bool clickEvent;
        void onBaseClickHandler() {
            cout << "no click event registred" << endl;
        }
    public:
        BaseHandler() {
            this->next = nullptr;
            this->clickEvent = false;
        }
        void setNext(Handler* h) override {
            this->next = h;
        }
        void setClickEvent(bool clickEvent) {
            this->clickEvent = clickEvent;
        }
        virtual void onClickHandler() override = 0;
};

class DialogHandler: public BaseHandler {
    public: 
        DialogHandler(): BaseHandler() {
        }
        void onClickHandler() override {
            if (this->clickEvent) {
                cout << "click event handled by dialog" << endl;
            } else if (this->next) {
                this->next->onClickHandler();
            } else {
                this->onBaseClickHandler();
            }
        }
};

class AlertHandler: public BaseHandler {
    public: 
        AlertHandler(): BaseHandler() {
        }
        void onClickHandler() override {
            if (this->clickEvent) {
                cout << "click event handled by alert" << endl;
            } else if (this->next) {
                this->next->onClickHandler();
            } else {
                this->onBaseClickHandler();
            }
        }
};

int main() {
    BaseHandler* alertHandler = new AlertHandler();
    BaseHandler* dialogHandler = new DialogHandler();

    // no click event registred
    alertHandler->onClickHandler();

    // no click event registred
    dialogHandler->onClickHandler();

    dialogHandler->setClickEvent(true);

    alertHandler->setNext(dialogHandler);

    // click event handled by dialog
    alertHandler->onClickHandler();

    alertHandler->setClickEvent(true);

    // click event handled by alert
    alertHandler->onClickHandler();

    // click event handled by dialog
    dialogHandler->onClickHandler();

    return 0;
}

