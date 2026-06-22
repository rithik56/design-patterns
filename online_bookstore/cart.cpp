#include "cart.hpp"
#include "book.hpp"

Cart::Cart()
{
    this->cost = 0;
}
void Cart::addBook(Book *book)
{
    this->books[book]++;
    this->cost += book->getCost();
}
void Cart::removeBook(Book *book)
{
    this->books[book]--;
    this->cost -= book->getCost();
    if (this->books[book] == 0)
    {
        this->books.erase(book);
    }
}

void Cart::clearCart()
{
    this->cost = 0;
    this->books.clear();
}

double Cart::getCost()
{
    return this->cost;
}

unordered_map<Book*, int>& Cart::getBooks() {
    return this->books;
}