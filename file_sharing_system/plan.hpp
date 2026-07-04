#pragma once

#include "common.hpp"

class Plan {
    private:
        int id;
        PLAN_ENUM name;
        double size;
        double cost;
    public:
        Plan(int id, PLAN_ENUM name, double size, double cost);
        double getSize();
};