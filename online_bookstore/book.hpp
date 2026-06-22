#pragma once

#include "common.hpp"

class Review;

class Book {
    private:
        int id;
        string name;
        GENRE_TYPE genre;
        string author;
        vector<Review*> reviews;
        double cost;

    public:
        Book(int id, string name, GENRE_TYPE genre, string author, double cost);
        int getId();
        double getCost();
        void addReview(Review* review);
};