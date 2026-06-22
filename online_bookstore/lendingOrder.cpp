#include "lendingOrder.hpp"

LendingOrder::LendingOrder(int id, int userId, unordered_map<Book*, int> books, double itemsCost, int paymentId, pair<int, int> address, int numberOfDays, string borrowed_at, string due_date, PAYMENT_METHOD paymentMethod) : Order(id, userId, books, itemsCost, paymentId, address)
{
    this->numberOfDays = numberOfDays;
    this->status = LENDING_ORDER_STATUS::CREATED_LENDING_ORDER;
    this->borrowed_at = borrowed_at;
    this->due_date = due_date;
    this->return_date = "";
    this->paymentMethod = paymentMethod;
}

void LendingOrder::setStatus(LENDING_ORDER_STATUS status) {
    this->status = status;
    if (this->status == LENDING_ORDER_STATUS::RETURN_REQUEST_RECEIVED) {
        this->return_date = "18/07/2026";
    }
}

double LendingOrder::calculateFine() {
    return 0;
}

PAYMENT_METHOD LendingOrder::getPaymentMethod() {
    return this->paymentMethod;
}