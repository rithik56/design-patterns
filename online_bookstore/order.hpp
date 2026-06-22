#pragma once

#include "common.hpp"

class Book;

class Order {
    protected:
        int id;
        int userId;
        unordered_map<Book*, int> books;
        double itemsCost;
        vector<int> paymentHistory;
        pair<int, int> address;
        string ordered_at;
    public:
        Order(int id, int userId, unordered_map<Book*, int> books, double itemsCost, int paymentId, pair<int, int> address);
        int getId();
        double getItemsCost();
        unordered_map<Book*, int>& getBooks();
        void addPayment(int paymentId);
        int getPaymentId();
};