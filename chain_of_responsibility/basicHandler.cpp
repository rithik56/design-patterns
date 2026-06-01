#include "basicHandler.hpp"

BasicHandler::BasicHandler(Handler* next) : Handler(next) {

}

void BasicHandler::handleRequest(string message) {
    if (message == "BASIC LEVEL INCIDENCE") {
        cout << "request handled by base handler" << endl;
    } else if (this->next) {
        this->next->handleRequest(message);
    } else {
        cout << "request not handled" << endl;
    }
}