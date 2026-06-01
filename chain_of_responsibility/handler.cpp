#include "handler.hpp"

Handler::Handler(Handler* next) {
    this->next = next;
}

void Handler::setNext(Handler* next) {
    this->next = next;
}

