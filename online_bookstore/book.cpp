#include "book.hpp"

Book::Book(int id, string name, GENRE_TYPE genre, string author, double cost) {
    this->id = id;
    this->name = name;
    this->genre = genre;
    this->author = author;
    this->cost = cost;
}

int Book::getId() {
    return this->id;
}

double Book::getCost() {
    return this->cost;
}

void Book::addReview(Review* review) {
    this->reviews.push_back(review);
}