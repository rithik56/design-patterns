#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void processPayment() = 0;
};

class Card : public Payment
{
    void processPayment() override
    {
        cout << "payment done by card" << endl;
    }
};

class UPI : public Payment
{
    void processPayment() override
    {
        cout << "payment done by UPI" << endl;
    }
};

class PaymentMode
{
public:
    virtual Payment *createPaymentMethod() = 0;

    void makePayment()
    {
        Payment *p = createPaymentMethod();
        p->processPayment();
    }
};

class CardPayment : public PaymentMode
{
    Payment *createPaymentMethod() override
    {
        return new Card();
    }
};

class UPIPayment : public PaymentMode
{
    Payment *createPaymentMethod() override
    {
        return new UPI();
    }
};

int main()
{
    string type = "Card";

    PaymentMode *p;

    if (type == "Card")
    {
        p = new CardPayment();
    }
    else
    {
        p = new UPIPayment();
    }

    // payment done by card
    p->makePayment();

    return 0;
}