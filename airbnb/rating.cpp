#include "rating.hpp"

Rating::Rating(double rating, string review)
{
    this->rating = rating;
    this->review = review;
}
double Rating::getRating()
{
    return this->rating;
}
string Rating::getReview()
{
    return this->review;
}
void Rating::show()
{
    cout << "Rating Details: " << endl;
    cout << "ratings: " << this->rating << endl;
    cout << "review: " << this->review << endl;
}