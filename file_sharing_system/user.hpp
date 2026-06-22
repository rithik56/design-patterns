#pragma once

#include "common.hpp"

class Plan;

class User {
    private:
        int id;
        string name;
        string email;
        Plan* plan;
    public:
        User(int id, string name, string email, Plan* plan);
};