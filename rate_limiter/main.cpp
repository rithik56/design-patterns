#include "leetcode.hpp"
#include "rateLimiterService.hpp"
#include "tokenBucketRateLimiter.hpp"
#include "fixedWindowRateLimiter.hpp"
#include "slidingWindowLogRateLimiter.hpp"
#include <thread>
#include <chrono>

// void task(User* user, Question* question) {
//     for (int i = 0; i < 5; i++) {
//         user->submitSolution(question->getId(), "solution");
//         this_thread::sleep_for(20s);
//     }
// }

int main()
{
    Leetcode *leetcode = Leetcode::getInstance();
    RateLimiterService *rateLimiterService = RateLimiterService::getInstance();
    rateLimiterService->setRateLimiter(new TokenBuckerRateLimiter());
    // rateLimiterService->setRateLimiter(new FixedWindowRateLimiter());
    // rateLimiterService->setRateLimiter(new SlidingWindowLogRateLimiter());
    User *userA = leetcode->addUser(newUserId++, "A", FREE);
    User *userB = leetcode->addUser(newUserId++, "B", PREMIUM);
    Question *questionA = leetcode->addQuestion(newQuestionId++, "Two Sum");
    Question *questionB = leetcode->addQuestion(newQuestionId++, "Three Sum");
    // sliding window output
    // user A request accepted
    // user A request accepted
    // user A request accepted
    // user A request accepted
    // sliding window log output
    // user A request accepted
    // user A request accepted
    // user A request accepted
    // user A request rejected
    // token bucket output
    // user A request accepted
    // user A request accepted
    // user A request accepted
    // user A request rejected
    userA->submitSolution(questionA->getId(), "solution of two sum");
    this_thread::sleep_for(9s);
    userA->submitSolution(questionA->getId(), "solution of two sum");
    this_thread::sleep_for(1s);
    userA->submitSolution(questionA->getId(), "solution of two sum");
    userA->submitSolution(questionA->getId(), "solution of two sum");

    // for (int i = 0; i < 10; i++)
    // {
    //     // user A request accepted
    //     // user A request accepted
    //     // user A request rejected
    //     // user A request rejected
    //     // user A request rejected
    //     // user A request rejected
    //     // user A request rejected
    //     // user A request rejected
    //     // user A request rejected
    //     // user A request rejected
    //     // userA->submitSolution(questionA->getId(), "solution of two sum");
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // userB->submitSolution(questionA->getId(), "solution of two sum");
    // }

    // for (int i = 0; i < 20; i++)
    // {
    //     // user A request accepted
    //     // user A request accepted
    //     // user A request accepted
    //     // user A request rejected
    //     // user A request accepted
    //     // user A request rejected
    //     // user A request accepted
    //     // user A request rejected
    //     // user A request accepted
    //     // user A request rejected
    //     // 2;
    //     // userA->submitSolution(questionA->getId(), "solution of two sum");
    // }

    // // thread t1(task, userA, questionA);
    // // thread t2(task, userA, questionA);
    // // thread t3(task, userA, questionA);
    // // thread t4(task, userA, questionA);

    // // t1.join();
    // // t2.join();
    // // t3.join();
    // // t4.join();

    // for (int i = 0; i < 20; i++)
    // {
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request accepted
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // user B request rejected
    //     // userB->submitSolution(questionA->getId(), "solution of two sum");
    //     // this_thread::sleep_for(1s);
    // }

    return 0;
}