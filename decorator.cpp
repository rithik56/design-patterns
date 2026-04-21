#include<iostream>
using namespace std;

class Dress {
    public:
        virtual string wear() = 0;
};

class BasicDress: public Dress {
    private:
        string outfit;
    public: 
        BasicDress(string dress) {
            this->outfit = dress;
        }
        string wear() {
            return this->outfit;
        }
};

class DressDecorator: public Dress {
    protected: 
        Dress* wrapped;
    public:
        DressDecorator(Dress* dress) {
            this->wrapped = dress;
        }
        virtual string wear() {
            return this->wrapped->wear();
        }
};

class CoatDecorator: public DressDecorator {
    public:
        CoatDecorator(Dress* d) : DressDecorator(d) {}
        // wear step could differ depending on what the user has worn till now
        string wear() override {
            return this->wrapped->wear() + "+ Coat ";
        }
};

class TieDecorator: public DressDecorator {
    public:
        TieDecorator(Dress* d) : DressDecorator(d) {}
        // wear step could differ depending on what the user has worn till now
        string wear() override {
            return this->wrapped->wear() + "+ Tie ";
        }
};

int main() {
    Dress* source = new BasicDress("Shirt + Pant ");
    bool wearCoat = true;
    bool wearTie = true;

    if (wearCoat) {
        source = new CoatDecorator(source);
    }

    if (wearTie) {
        source = new TieDecorator(source);
    }

    // Shirt + Pant + Coat + Tie 
    cout << source->wear() << endl;

    return 0;
}