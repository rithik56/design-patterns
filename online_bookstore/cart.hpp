#pragma once

#include "common.hpp"

class Book;

class Cart {
    private:
        unordered_map<Book*, int> books;
        double cost;
    public:
        Cart();
        void addBook(Book* book);
        void removeBook(Book* book);
        void clearCart();
        double getCost();
        unordered_map<Book*, int>& getBooks();
};