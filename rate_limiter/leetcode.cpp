#include "leetcode.hpp"

#include "rateLimiterService.hpp"

Leetcode* Leetcode::leetcode = nullptr;
mutex Leetcode::mtx;

Leetcode::Leetcode() {

}

Leetcode* Leetcode::getInstance() {
    if (leetcode == nullptr) {
        mtx.lock();
        if (leetcode == nullptr) {
            leetcode = new Leetcode();
        }
        mtx.unlock();
    }
    return leetcode;
}

User* Leetcode::addUser(int id, string name, USER_TYPE userType) {
    this->users[id] = new User(id, name, userType);
    RateLimiterService::getInstance()->setUserLimit(id, rateLimitMap[userType]);
    return this->users[id];
}

Question* Leetcode::addQuestion(int id, string desc) {
    this->questions[id] = new Question(id, desc);
    return this->questions[id];
}

void Leetcode::checkSolution(int user_id, int question_id, string code) {
    bool accept = RateLimiterService::getInstance()->handleRequest(user_id);
    if (accept) {
        cout << "user " << this->users[user_id]->getName() << " request accepted" << endl;
    } else {
        cout << "user " << this->users[user_id]->getName() << " request rejected" << endl;
    }
}