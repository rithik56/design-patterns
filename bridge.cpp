#include<iostream>
using namespace std;

class FlyingVehicle {
    protected:
        int rank;
        string name;
    public:
        virtual string fly() = 0;
        virtual int getRank() = 0;
};

class Plane: public FlyingVehicle {
    public:
        Plane(string name, int rank) {
            this->name = name;
            this->rank = rank;
        }
        string fly() override {
            return "fly the " + this->name;
        }
        int getRank() override {
            return this->rank;
        }
};

class Helicopter: public FlyingVehicle {
    public:
        Helicopter(string name, int rank) {
            this->name = name;
            this->rank = rank;
        }
        string fly() override {
            return "fly the " + this->name;
        }
        int getRank() override {
            return this->rank;
        }
};

class Pilot {
    private:
        FlyingVehicle* vehicle;
        string name;
        int rank;
    public:
        Pilot(string name, int rank, FlyingVehicle* vehicle) {
            this->name = name;
            this->rank = rank;
            this->vehicle = vehicle;
        }
        void fly() {
            if (this->rank >= vehicle->getRank()) {
                cout << this->vehicle->fly() + " " + this->name << endl;
            } else {
                cout << this->name << " is not eligible to fly this vehicle" << endl;
            }
        }
        void setVehicle(FlyingVehicle* vehicle) {
            this->vehicle = vehicle;
        }
};

int main() {
    Helicopter* helicopter = new Helicopter("helicopter", 5);
    Plane* plane = new Plane("plane", 2);

    // instance of helicopter pilot
    Pilot* pilot = new Pilot("jaskirat", 6, helicopter);

    // fly the helicopter jaskirat
    pilot->fly();

    Pilot* anotherPilot = new Pilot("rahul", 3, helicopter);

    // rahul is not eligible to fly this vehicle
    anotherPilot->fly();

    anotherPilot->setVehicle(plane);

    // fly the plane rahul
    anotherPilot->fly();

    return 0;
}