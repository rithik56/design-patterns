#include "bookStore.hpp"
#include "book.hpp"
#include "user.hpp"
#include "cart.hpp"
#include "orderManager.hpp"
#include "purchaseOrder.hpp"
#include "lendingOrder.hpp"

int main()
{
    BookStore *bookStore = BookStore::getInstance();
    OrderManager *orderManager = OrderManager::getInstance();
    Book *book1 = new Book(1, "book1", GENRE_TYPE::BUSINESS, "anshul", 350);
    Book *book2 = new Book(2, "book2", GENRE_TYPE::DOCUMENTARY, "bhavya", 450);
    Book *book3 = new Book(3, "book3", GENRE_TYPE::MATHEMATICS, "cathy", 550);
    Book *book4 = new Book(4, "book4", GENRE_TYPE::ROMANTIC, "damon", 650);
    bookStore->addBook(book1, 2);
    bookStore->addBook(book2, 3);
    bookStore->addBook(book3, 4);
    bookStore->addBook(book4, 5);
    User *user1 = bookStore->addUser("rithik", "9643093318");
    User *user2 = bookStore->addUser("rahul", "9643093317");
    //     book id: 4quantity: 5
    // book id: 3quantity: 4
    // book id: 2quantity: 3
    // book id: 1quantity: 2
    bookStore->displayBooks();
    Cart *cart1 = user1->getCart();
    cart1->addBook(book1);
    cart1->addBook(book1);
    cart1->addBook(book2);
    PurchaseOrder *purchaseOrder1 = user1->purchaseBooks(PAYMENT_METHOD::UPI, make_pair(0, 0));
    orderManager->updatePurchaseOrderStatus(purchaseOrder1->getId(), PURCHASE_ORDER_STATUS::OUT_FOR_DELIVERY);
    orderManager->updatePurchaseOrderStatus(purchaseOrder1->getId(), PURCHASE_ORDER_STATUS::DELIVERED);
    //     book id: 4quantity: 5
    // book id: 3quantity: 4
    // book id: 2quantity: 2
    // book id: 1quantity: 0
    bookStore->displayBooks();
    Cart *cart2 = user2->getCart();
    cart2->addBook(book4);
    cart2->addBook(book3);
        // either buy a membership or renew your membership
    user2->lendBooks(PAYMENT_METHOD::CARD, make_pair(10, 10), 30);
    // payment done by card
    user2->purchaseMembership(MEMBERSHIP_NAME::ANNUAL, PAYMENT_METHOD::CARD);
    // payment done by card
    LendingOrder* lendingOrder2 = user2->lendBooks(PAYMENT_METHOD::CARD, make_pair(10, 10), 30);
    orderManager->updateLendingOrderStatus(purchaseOrder1->getId(), LENDING_ORDER_STATUS::OUT_FOR_DELIVERY_LENDING_ORDER);
    orderManager->updateLendingOrderStatus(purchaseOrder1->getId(), LENDING_ORDER_STATUS::DELIVERED_LENDING_ORDER);
//     book id: 4quantity: 4
// book id: 3quantity: 3
// book id: 2quantity: 2
// book id: 1quantity: 0
    bookStore->displayBooks();
    user2->returnBooks(lendingOrder2);
    orderManager->updateLendingOrderStatus(lendingOrder2->getId(), LENDING_ORDER_STATUS::RETURNED_TO_BOOKSTORE);
    bookStore->displayBooks();
    user2->writeReview("the book was an eye opener for me", 4.0, book4->getId());
    cart1->addBook(book4);
    cart1->addBook(book3);
    PurchaseOrder* purchaseOrder12 = user1->purchaseBooks(PAYMENT_METHOD::CARD, make_pair(0, 0));
//     book id: 4quantity: 4
// book id: 3quantity: 3
// book id: 2quantity: 2
// book id: 1quantity: 0
    bookStore->displayBooks();
    // payment refunded by card
    user1->cancelPurchaseOrder(purchaseOrder12);
//     book id: 4quantity: 5
// book id: 3quantity: 4
// book id: 2quantity: 2
// book id: 1quantity: 0
    bookStore->displayBooks();
    // payment done by card
    user2->renewMembership();
    cart1->addBook(book4);
    cart1->addBook(book3);
    user1->purchaseMembership(MEMBERSHIP_NAME::MONTHLY, PAYMENT_METHOD::CARD);
    LendingOrder* lendingOrder1 = user1->lendBooks(PAYMENT_METHOD::UPI, make_pair(0, 0), 7);
    bookStore->displayBooks();
    user1->cancelLendingOrder(lendingOrder1);
    bookStore->displayBooks();
    return 0;
}