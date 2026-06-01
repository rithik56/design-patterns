#pragma once

#include "common.hpp"
#include "handler.hpp"

class AdvancedHandler: public Handler {
    public:
        AdvancedHandler(Handler* next);
        void handleRequest(string message) override;
};