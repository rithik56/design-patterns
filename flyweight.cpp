#include<iostream>
using namespace std;

class StarType {
    private:
        string name;
    public:
        StarType(string name) {
            this->name = name;
        }
        void draw(int x, int y) {
            cout << "draw " << this->name << " at " << x << " " << y << endl;
        }
};

class StarTypeFactory {
    private:
        static unordered_map<string, StarType*> type;
    public:
        static StarType* getStarType(string name) {
            if (type.find(name) != type.end()) {
                return type[name];
            }
            StarType* newType = new StarType(name);
            type[name] = newType;
            return newType;
        }
};

unordered_map<string, StarType*> StarTypeFactory::type;

class Star {
    private:
        int x;
        int y;
        StarType* starType;
    public:
        Star(string name, int x, int y) {
            this->starType = StarTypeFactory::getStarType(name);
            this->x = x;
            this->y = y;
        }
        void draw() {
            this->starType->draw(this->x, this->y);
        }
};

class Sky {
    private:
        vector<Star*> stars;
    public:
        Sky() {

        }
        void addStar(string name, int x, int y) {
            Star* star = new Star(name, x, y);
            this->stars.push_back(star);
        }
        void draw() {
            for (int i = 0; i < this->stars.size(); i++) {
                this->stars[i]->draw();
            }
        }
};

int main() {
    Sky* sky = new Sky();
    for (int i = 0; i < 1000; i++) {
        sky->addStar("star1", i, i);
    }
    for (int j = 1001; j < 2000; j++) {
        sky->addStar("star2", j, j);
    }
    sky->draw();
    return 0;
}
