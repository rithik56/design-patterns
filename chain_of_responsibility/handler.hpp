#pragma once

#include "common.hpp"

class Handler {
    protected:
        Handler* next;
    public:
        Handler(Handler* next);
        void setNext(Handler* next);
        virtual void handleRequest(string message) = 0;
};