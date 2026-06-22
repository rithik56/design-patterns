#pragma once

#include "common.hpp"

class User;
class Book;

class BookStore {
    private:
        BookStore();
        static BookStore* instance;
        static mutex mtx;
        unordered_map<int, int> bookInventory;
        unordered_map<int, User*> users;
        unordered_map<int, Book*> books;
    public:
        static BookStore* getInstance();
        void displayBooks();
        void addBook(Book* book, int numberOfBooks);
        void removeBook(int bookId);
        User* addUser(string name, string phone);
        void removeUser(int userId);
        void handlePurchaseBooks(unordered_map<Book*, int> books);
        void handleReturnBooks(unordered_map<Book*, int> books);
        Book* getBookById(int bookId);
};