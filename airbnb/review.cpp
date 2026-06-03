#include "review.hpp"
#include "user.hpp"
#include "rating.hpp"

Review::Review(int id, Rating *rating)
{
    this->id = id;
    this->rating = rating;
}
void Review::showReview()
{
    User *reviewer = this->getReviewer();
    cout << "name: " << reviewer->getName() << endl;
    this->rating->show();
}