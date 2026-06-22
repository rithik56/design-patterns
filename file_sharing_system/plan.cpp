#include "plan.hpp"

Plan::Plan(int id, PLAN_ENUM name, double size, double cost) {
    this->id = id;
    this->name = name;
    this->size = size;
    this->cost = cost;
}