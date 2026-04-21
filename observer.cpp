#include <iostream>
using namespace std;

class Publisher;

class Subscriber
{
public:
    virtual void update(unordered_map<string, string> variables) = 0;
};

class Publisher
{
public:
    virtual void subscribe(string eventType, Subscriber *s) = 0;
    virtual void unsubscribe(string eventType, Subscriber *s) = 0;
};

class State : public Publisher
{
private:
    unordered_map<string, unordered_map<Subscriber *, int>> listeners;
    unordered_map<string, string> variables;
    void notifySubscribers(string eventType)
    {
        unordered_map<Subscriber *, int> subscribers = listeners[eventType];
        for (auto it = subscribers.begin(); it != subscribers.end(); it++)
        {
            it->first->update(this->variables);
        }
    }

public:
    State(unordered_map<string, string> variables)
    {
        this->variables = variables;
    }
    void subscribe(string eventType, Subscriber *s) override
    {
        this->listeners[eventType][s] = 1;
    }
    void unsubscribe(string eventType, Subscriber *s) override
    {
        this->listeners[eventType].erase(s);
    }
    void updateState(unordered_map<string, string> variables)
    {
        for (auto it = variables.begin(); it != variables.end(); it++)
        {
            string key = it->first;
            string val = it->second;
            if (this->variables[key] != val)
            {
                this->variables[key] = val;
                this->notifySubscribers(key);
            }
        }
    }
    unordered_map<string, string> getState() {
        return this->variables;
    }
};

class Component1 : public Subscriber
{
private:
    void renderUI(unordered_map<string, string> variables)
    {
        string variable1 = variables["variable1"];
        cout << "Component 1 renders: " << variable1 << endl;
    }

public:
    Component1(unordered_map<string, string> variables)
    {
        renderUI(variables);
    }
    void update(unordered_map<string, string> variables) override
    {
        renderUI(variables);
    }
};

class Component2 : public Subscriber
{
private:
    void renderUI(unordered_map<string, string> variables)
    {
        string variable1 = variables["variable1"];
        string variable2 = variables["variable2"];
        cout << "Component 2 renders: " << variable1 << " " << variable2 << endl;
    }

public:
    Component2(unordered_map<string, string> variables)
    {
        renderUI(variables);
    }
    void update(unordered_map<string, string> variables) override
    {
        renderUI(variables);
    }
};

int main()
{
    unordered_map<string, string> initialState;
    initialState["variable1"] = "1";
    initialState["variable2"] = "2";
    initialState["variable3"] = "3";
    State* state = new State(initialState);

    // Component 1 renders: 1
    Component1* header = new Component1(state->getState());

    // Component 2 renders: 1 2
    Component2* footer = new Component2(state->getState());

    state->subscribe("variable1", header);

    state->subscribe("variable1", footer);
    state->subscribe("variable2", footer);

    initialState["variable1"] = "2";
    initialState["variable2"] = "1";

    state->updateState(initialState);

    // Component 1 renders: 2
    // Component 2 renders: 2 2
    // Component 2 renders: 2 1

    // Component 2 rendered twice since it subscribed to variable1 and variable2

    initialState["variable3"] = "4";
    state->updateState(initialState);

    // no log since no component subscribed to variable3
    cout << "no log since no component subscribed to variable3" << endl;

    initialState["variable2"] = "3";
    state->updateState(initialState);

    // Component 2 renders: 2 3

    state->unsubscribe("variable2", footer);

    initialState["variable2"] = "5";
    state->updateState(initialState);

    // no log since no component subscribed to variable2
    cout << "no log since no component subscribed to variable2" << endl;

    return 0;
}