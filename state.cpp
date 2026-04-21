#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ReadyState;
class CheckoutState;
class PaymentProcessingState;
class CompletedState;

class State {
public:
    virtual void addItem(string item) {}
    virtual void doCheckout() {}
    virtual void cancelCheckout() {}
    virtual void doPayment() {}
    virtual void takeItems() {}
};

class Machine {
private:
    State *state;
    vector<string> items;

    void setState(State *state);
    void paymentSuccessful();

public:
    Machine();

    void addItem(string name);
    void doCheckout();
    void cancelCheckout();
    void doPayment();
    void takeItems();

    friend class ReadyState;
    friend class CompletedState;
    friend class CheckoutState;
};

class ReadyState : public State {
private:
    Machine *machine;
public:
    ReadyState(Machine *machine);
    void addItem(string item) override;
    void doCheckout() override;
};

class CheckoutState : public State {
private:
    Machine *machine;
public:
    CheckoutState(Machine *machine);
    void cancelCheckout() override;
    void doPayment() override;
};

class PaymentProcessingState : public State {
private:
    Machine *machine;
public:
    PaymentProcessingState(Machine *machine);
};

class CompletedState : public State {
private:
    Machine *machine;
public:
    CompletedState(Machine *machine);
    void takeItems() override;
};

Machine::Machine() {
    state = new ReadyState(this);
}

void Machine::setState(State *state) {
    this->state = state;
}

void Machine::paymentSuccessful() {
    this->state = new CompletedState(this);
}

void Machine::addItem(string name) {
    state->addItem(name);
}

void Machine::doCheckout() {
    state->doCheckout();
}

void Machine::cancelCheckout() {
    state->cancelCheckout();
}

void Machine::doPayment() {
    state->doPayment();
}

void Machine::takeItems() {
    state->takeItems();
}

ReadyState::ReadyState(Machine *machine) {
    this->machine = machine;
}

void ReadyState::addItem(string item) {
    machine->items.push_back(item);
}

void ReadyState::doCheckout() {
    machine->setState(new CheckoutState(machine));
}

CheckoutState::CheckoutState(Machine *machine) {
    this->machine = machine;
}

void CheckoutState::cancelCheckout() {
    machine->setState(new ReadyState(machine));
}

void CheckoutState::doPayment() {
    machine->setState(new PaymentProcessingState(machine));
    machine->paymentSuccessful();
}

PaymentProcessingState::PaymentProcessingState(Machine *machine) {
    this->machine = machine;
}

CompletedState::CompletedState(Machine *machine) {
    this->machine = machine;
}

void CompletedState::takeItems() {
    machine->items.clear();
    machine->setState(new ReadyState(machine));
}

int main() {
    Machine *machine = new Machine();

    machine->addItem("chocolate");
    machine->addItem("apple");

    machine->doCheckout();
    machine->cancelCheckout();

    machine->addItem("banana");

    machine->doCheckout();
    machine->doPayment();

    machine->takeItems();

    return 0;
}