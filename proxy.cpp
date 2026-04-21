#include<iostream>
using namespace std;

class McDInterface {
    public:
        virtual void serveVeg() = 0;
        virtual void serveNonVeg() = 0;
};

class McD: public McDInterface {
    public:
        McD() {

        }
        void serveVeg() {
            cout << "veg order placed successfully" << endl;
        }
        void serveNonVeg() {
            cout << "non veg order placed successfully" << endl;
        }
};

class McDIndia: public McDInterface {
    private:
        McD* target;
        string state;
        McD* getInstance() {
            if (this->target == nullptr) {
                this->target = new McD();
            }
            return this->target;
        }
    public:
        McDIndia(string state) {
            target = nullptr;
            this->state = state;
        }
        void setState(string state) {
            this->state = state;
        }
        void serveVeg() {
            McD* target = getInstance();
            target->serveVeg();
        }
        void serveNonVeg() {
            McD* target = getInstance();
            if (this->state == "Ayodhya") {
                cout << "non veg not allowed at this place" << endl;
            } else {
                target->serveNonVeg();
            }
        }
};


int main() {
    string state = "Ayodhya";

    McDIndia* McDIndiaOutlet = new McDIndia(state);

    // non veg not allowed at this place
    McDIndiaOutlet->serveNonVeg();
    
    // veg order placed successfully
    McDIndiaOutlet->serveVeg();

    McDIndiaOutlet->setState("Delhi");

    // non veg order placed successfully
    McDIndiaOutlet->serveNonVeg();

    return 0;
}