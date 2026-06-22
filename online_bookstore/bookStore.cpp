#include "bookStore.hpp"
#include "book.hpp"
#include "user.hpp"

BookStore *BookStore::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new BookStore();
        }
        mtx.unlock();
    }
    return instance;
}

BookStore *BookStore::instance = nullptr;
mutex BookStore::mtx;

BookStore::BookStore() {

}

void BookStore::displayBooks()
{
    // display all the books along with inventory stats
    for (auto it = this->books.begin(); it != this->books.end(); it++)
    {
        cout << "book id: " << it->first;
        cout << "quantity: " << this->bookInventory[it->first] << endl;
    }
}
void BookStore::addBook(Book *book, int numberOfBooks)
{
    int bookId = book->getId();
    this->books[bookId] = book;
    this->bookInventory[bookId] = numberOfBooks;
}
void BookStore::removeBook(int bookId)
{
    this->books.erase(bookId);
    this->bookInventory.erase(bookId);
}
User *BookStore::addUser(string name, string phone)
{
    User *user = new User(userId, name, phone);
    this->users[userId++] = user;
    return user;
}
void BookStore::removeUser(int userId)
{
    this->users.erase(userId);
}

void BookStore::handlePurchaseBooks(unordered_map<Book *, int> books)
{
    for (auto it = books.begin(); it != books.end(); it++)
    {
        int bookId = it->first->getId();
        this->bookInventory[bookId] -= it->second;
    }
}
void BookStore::handleReturnBooks(unordered_map<Book *, int> books)
{
    for (auto it = books.begin(); it != books.end(); it++)
    {
        int bookId = it->first->getId();
        this->bookInventory[bookId] += it->second;
    }
}

Book* BookStore::getBookById(int bookId) {
    return this->books[bookId];
}