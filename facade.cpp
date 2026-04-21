#include<iostream>
using namespace std;

class Card {
    protected:
        string cardNumber;
    public:
        virtual void block() = 0;
};

class DebitCard: public Card {
    public:
        DebitCard(string cardNumber) {
            this->cardNumber = cardNumber;
        }
        void block() override {
            cout << "blocking debit card with number " << this->cardNumber << endl;
        }
};

class CreditCard: public Card {
    public:
        CreditCard(string cardNumber) {
            this->cardNumber = cardNumber;
        }
        void block() override {
            cout << "blocking credit card with number " << this->cardNumber << endl;
        }
};

class Account {
    public:
        Account() {

        }
        void blockCard(Card* card) {
            card->block();
        }
};

class CustomerHelpline {
    public:
        void blockCard(string cardNumber, string cardType) {
            Card* card;
            if (cardType == "debit") {
                card = new DebitCard(cardNumber);
            } else {
                card = new CreditCard(cardNumber);
            }
            Account* account = new Account();
            account->blockCard(card);
        }
};

int main() {
    CustomerHelpline* customerHelpline = new CustomerHelpline();
    // blocking credit card with number 1234
    customerHelpline->blockCard("1234", "credit");
    return 0;
}

