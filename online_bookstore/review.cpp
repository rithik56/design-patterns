#include "review.hpp"

Review::Review(int userId, int bookId, string txt, double ratings) {
    this->userId = userId;
    this->bookId = bookId;
    this->txt = txt;
    this->ratings = ratings;
    this->reviewedAt = "17/06/2026";
}