#include "basicHandler.hpp"
#include "advancedHandler.hpp"

int main() {
    AdvancedHandler* AdvancedHandler = new class AdvancedHandler(NULL);
    BasicHandler* BasicHandler = new class BasicHandler(AdvancedHandler);
    // request handled by base handler
    // request handled by advanced handler
    string message1 = "BASIC LEVEL INCIDENCE";
    string message2 = "ADVANCED LEVEL INCIDENCE";
    BasicHandler->handleRequest(message1);
    BasicHandler->handleRequest(message2);
    return 0;
}
