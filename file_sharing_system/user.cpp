#include "user.hpp"

User::User(int id, string name, string email, Plan* plan) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->plan = plan;
}