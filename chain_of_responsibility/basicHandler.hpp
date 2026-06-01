#pragma once

#include "common.hpp"
#include "handler.hpp"

class BasicHandler: public Handler {
    public:
        BasicHandler(Handler* next);
        void handleRequest(string message) override;
};