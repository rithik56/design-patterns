#include "order.hpp"
#include "book.hpp"

Order::Order(int id, int userId, unordered_map<Book *, int> books, double itemsCost, int paymentId, pair<int, int> address)
{
    this->id = id;
    this->userId = userId;
    this->books = books;
    this->itemsCost = itemsCost;
    this->address = address;
    this->ordered_at = "17/06/2026";
    this->paymentHistory.push_back(paymentId);
}

int Order::getId()
{
    return this->id;
}
double Order::getItemsCost()
{
    return this->itemsCost;
}
unordered_map<Book *, int> &Order::getBooks()
{
    return this->books;
}

void Order::addPayment(int paymentId) {
    this->paymentHistory.push_back(paymentId);
}

int Order::getPaymentId() {
    return this->paymentHistory[this->paymentHistory.size()- 1];
}