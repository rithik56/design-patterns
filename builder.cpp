#include <iostream>
using namespace std;

class Pizza
{
public:
    Pizza()
    {
    }

    bool hasOnion;
    bool hasCrispCapsicum;
    bool hasFreshTomato;
    bool hasMushroom;
    bool hasCapsicumYellow;
    bool hasBellPepper;
    bool hasRedBellPepper;
    bool hasJalapeno;
    bool hasRedPaprika;
    bool hasExoticHerbs;
    bool hasPaneer;
    bool hasRedPepper;
    bool hasExoticMexicanHerbs;
    bool hasGoldenCorn;
    bool hasBlackOlives;
    bool hasExtraCheese;
};

class PizzaDesc
{
public:
    PizzaDesc() {};

    vector<string> toppings;
    string getDescription()
    {
        string ans = "";
        for (int i = 0; i < this->toppings.size() - 1; i++)
        {
            ans += this->toppings[i] + ", ";
        }
        ans += this->toppings[this->toppings.size() - 1];
        return ans;
    }
};

class Builder
{
public:
    virtual void reset() = 0;
    virtual void addOnion() = 0;
    virtual void addCrispCapsicum() = 0;
    virtual void addFreshTomato() = 0;
    virtual void addMushroom() = 0;
    virtual void addCapsicumYellow() = 0;
    virtual void addBellPepper() = 0;
    virtual void addRedBellPepper() = 0;
    virtual void addJalapeno() = 0;
    virtual void addRepPaprika() = 0;
    virtual void addExoticHerbs() = 0;
    virtual void addPaneer() = 0;
    virtual void addRedPepper() = 0;
    virtual void addExoticMexicanHerbs() = 0;
    virtual void addGoldenCorn() = 0;
    virtual void addBlackOlives() = 0;
    virtual void addExtraCheese() = 0;
};

class PizzaBuilder : public Builder
{
private:
    Pizza *pizza;

public:
    PizzaBuilder()
    {
        this->pizza = new Pizza();
    };

    void reset()
    {
        this->pizza = new Pizza();
    }
    void addOnion()
    {
        this->pizza->hasOnion = true;
    }
    void addCrispCapsicum()
    {
        this->pizza->hasCrispCapsicum = true;
    }
    void addFreshTomato()
    {
        this->pizza->hasFreshTomato = true;
    }
    void addMushroom()
    {
        this->pizza->hasMushroom = true;
    }
    void addCapsicumYellow()
    {
        this->pizza->hasCapsicumYellow = true;
    }
    void addBellPepper()
    {
        this->pizza->hasBellPepper = true;
    }
    void addRedBellPepper()
    {
        this->pizza->hasRedBellPepper = true;
    }
    void addJalapeno()
    {
        this->pizza->hasJalapeno = true;
    }
    void addRepPaprika()
    {
        this->pizza->hasRedPaprika = true;
    }
    void addExoticHerbs()
    {
        this->pizza->hasExoticHerbs = true;
    }
    void addPaneer()
    {
        this->pizza->hasPaneer = true;
    }
    void addRedPepper()
    {
        this->pizza->hasRedPepper = true;
    }
    void addExoticMexicanHerbs()
    {
        this->pizza->hasExoticMexicanHerbs = true;
    }

    void addGoldenCorn()
    {
        this->pizza->hasGoldenCorn = true;
    }
    void addBlackOlives()
    {
        this->pizza->hasBlackOlives = true;
    }

    void addExtraCheese()
    {
        this->pizza->hasExtraCheese = true;
    }
    Pizza *getResult()
    {
        Pizza *product = this->pizza;
        this->pizza = new Pizza();
        return product;
    }
};

class PizzaDescBuilder : public Builder
{
private:
    PizzaDesc *pizzaDesc;

public:
    PizzaDescBuilder()
    {
        this->pizzaDesc = new PizzaDesc();
    }

    void reset()
    {
        this->pizzaDesc = new PizzaDesc();
    }
    void addOnion()
    {
        pizzaDesc->toppings.push_back("Onion");
    }
    void addCrispCapsicum()
    {
        pizzaDesc->toppings.push_back("Crisp Capsicum");
    }
    void addFreshTomato()
    {

        pizzaDesc->toppings.push_back("Fresh Tomato");
    }
    void addMushroom()
    {

        pizzaDesc->toppings.push_back("Mushroom");
    }
    void addCapsicumYellow()
    {

        pizzaDesc->toppings.push_back("Capsicum Yellow");
    }
    void addBellPepper()
    {

        pizzaDesc->toppings.push_back("Bell Pepper");
    }
    void addRedBellPepper()
    {

        pizzaDesc->toppings.push_back("Red Bell Pepper");
    }
    void addJalapeno()
    {

        pizzaDesc->toppings.push_back("Jalapeno");
    }
    void addRepPaprika()
    {

        pizzaDesc->toppings.push_back("Rep Paprika");
    }
    void addExoticHerbs()
    {

        pizzaDesc->toppings.push_back("Exotic Herbs");
    }
    void addPaneer()
    {

        pizzaDesc->toppings.push_back("Paneer");
    }
    void addRedPepper()
    {

        pizzaDesc->toppings.push_back("Red Pepper");
    }
    void addExoticMexicanHerbs()
    {

        pizzaDesc->toppings.push_back("Exotic Mexican Herbs");
    }

    void addGoldenCorn()
    {

        pizzaDesc->toppings.push_back("Golden Corn");
    }

    void addBlackOlives()
    {

        pizzaDesc->toppings.push_back("Black Olives");
    }

    void addExtraCheese()
    {

        pizzaDesc->toppings.push_back("Extra Cheese");
    }

    PizzaDesc *getResult()
    {
        PizzaDesc *product = this->pizzaDesc;
        this->pizzaDesc = new PizzaDesc();
        return product;
    }
};

class Director
{
private:
    Builder *b;

public:
    Director()
    {
    }

    void setBuilder(Builder *param)
    {
        this->b = param;
    }
    void make(string type)
    {
        if (type == "Farmhouse")
        {
            b->addOnion();
            b->addCrispCapsicum();
            b->addMushroom();
            b->addFreshTomato();
        }
    }
};

int main()
{
    PizzaBuilder *pizzaBuilder = new PizzaBuilder();
    Director *d = new Director();
    d->setBuilder(pizzaBuilder);
    d->make("Farmhouse");
    Pizza *pizza = pizzaBuilder->getResult();
    // 1 1 1 1
    cout << pizza->hasOnion << " " << pizza->hasCrispCapsicum << " " << pizza->hasMushroom << " " << pizza->hasFreshTomato << endl;
    PizzaDescBuilder *pizzaDescBuilder = new PizzaDescBuilder();
    d->setBuilder(pizzaDescBuilder);
    d->make("Farmhouse");
    PizzaDesc *pizzaDesc = pizzaDescBuilder->getResult();
    // Onion, Crisp Capsicum, Mushroom, Fresh Tomato
    cout << pizzaDesc->getDescription() << endl;
    return 0;
}
