#include<iostream>
#include<unordered_set>
using namespace std;

class Tree {
    public:
        virtual int sum() = 0;
        virtual Tree* clone() = 0;
};

class Leaf: public Tree {
    private:
        int val;
    public:
        Leaf(int val) {
            this->val = val;
        } 
        Leaf(Leaf* leaf): Leaf(leaf->val) {
        }
        int sum() override {
            return this->val;
        }
        Leaf* clone() override {
            return new Leaf(this);
        }
};

class Root: public Tree {
    private:
        unordered_set<Tree*> children;
        int val;
    public:
        Root(int val) {
            this->val = val;
        } 
        Root(Root* root): Root(root->val) {
            for (auto it = root->children.begin(); it != root->children.end(); it++) {
                this->children.insert((*it)->clone());
            }
        }
        void add(Tree* tree) {
            this->children.insert(tree);
        }
        void remove(Tree* tree) {
            this->children.erase(tree);
        }
        int sum() override {
            int sum = this->val;
            for (auto it = this->children.begin(); it != this->children.end(); it++) {
                sum += (*it)->sum();
            }
            return sum;
        }
        Root* clone() override {
            return new Root(this);
        }
};

int main() {
    Root* root = new Root(1);

    Leaf* leaf1 = new Leaf(2);
    Leaf* leaf2 = new Leaf(3);

    root->add(leaf1);
    root->add(leaf2);

    // 6 2 3
    cout << root->sum() << " " << leaf1->sum() << " " << leaf2->sum() << endl;

    Root* anotherRoot = new Root(5);

    anotherRoot->add(root->clone());

    // 11
    cout << anotherRoot->sum() << endl;

    return 0;
}
