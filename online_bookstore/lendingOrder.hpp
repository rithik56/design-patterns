#pragma once

#include "common.hpp"
#include "order.hpp"

class Book;

class LendingOrder: public Order {
    private:
        LENDING_ORDER_STATUS status;
        string borrowed_at;
        string due_date;
        string return_date;
        int numberOfDays;
        PAYMENT_METHOD paymentMethod;
    public:
        LendingOrder(int id, int userId, unordered_map<Book*, int> books, double itemsCost, int paymentId, pair<int, int> address, int numberOfDays, string borrowed_at, string due_date, PAYMENT_METHOD paymentMethod);
        void setStatus(LENDING_ORDER_STATUS status);
        double calculateFine();
        PAYMENT_METHOD getPaymentMethod();
};