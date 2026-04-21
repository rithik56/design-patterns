#include<iostream>
#include<unordered_set>
using namespace std;

class Item {
    private:
        string name;
        int price;
    public:
        Item() {
            this->name = "";
            this->price = 0;
        }
        Item(string name, int price) {
            this->name = name;
            this->price = price;
        }
        Item(Item* item): Item() {
            this->name = item->name;
            this->price = item->price;
        }
        void setName(string name) {
            this->name = name;
        }
        void setPrice(int price) {
            this->price = price;
        }
        Item* clone() {
            return new Item(this);
        }
        string getName() {
            return this->name;
        }
};

class ShoppingCart {
    private:
        unordered_set<Item*> items;
    public:
        ShoppingCart() {
        }
        ShoppingCart(ShoppingCart* shoppingCart): ShoppingCart() {
            for (auto it = shoppingCart->items.begin(); it != shoppingCart->items.end(); it++) {
                this->items.insert((*it)->clone());
            }
        }
        void addItem(Item* item) {
            this->items.insert(item);
        }
        void removeItem(Item* item) {
            this->items.erase(item);
        }
        void displayItems() {
            for (auto it = this->items.begin(); it != this->items.end(); it++) {
                cout << (*it)->getName() << " ";
            }
            cout << endl;
        }
        ShoppingCart* clone() {
            return new ShoppingCart(this);
        }
};

int main() {
    ShoppingCart* shoppingCart = new ShoppingCart();

    Item* item1 = new Item("apple", 20);

    Item* item2 = new Item("pineapple", 100);

    shoppingCart->addItem(item1);
    shoppingCart->addItem(item2);

    ShoppingCart* copy = shoppingCart->clone();

    shoppingCart->removeItem(item2);

    // apple
    shoppingCart->displayItems();

    // apple pineapple
    copy->displayItems();

    return 0;
}