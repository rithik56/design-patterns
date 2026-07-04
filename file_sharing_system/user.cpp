#include "user.hpp"
#include "storageService.hpp"
#include "plan.hpp"

User::User(int id, string name, string email, Plan *plan)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->plan = plan;
}
int User::getId()
{
    return this->id;
}
Plan *User::getPlan()
{
    return this->plan;
}
double User::getAvailableLimit() {
    double homeDirectorySize = StorageService::getInstance()->getDirectorySize(this);
    return this->plan->getSize() - homeDirectorySize;
}