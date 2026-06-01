#include "advancedHandler.hpp"

AdvancedHandler::AdvancedHandler(Handler* next) : Handler(next) {

}

void AdvancedHandler::handleRequest(string message) {
    if (message == "ADVANCED LEVEL INCIDENCE") {
        cout << "request handled by advanced handler" << endl;
    } else if (this->next) {
        this->next->handleRequest(message);
    } else {
        cout << "request not handled" << endl;
    }
}