#include "user.hpp"
#include "cart.hpp"
#include "orderManager.hpp"
#include "membership.hpp"
#include "bookStore.hpp"
#include "book.hpp"
#include "review.hpp"
#include "lendingOrder.hpp"
#include "purchaseOrder.hpp"

User::User(int id, string name, string phone)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->cart = new Cart();
    this->membership = nullptr;
}
int User::getId()
{
    return this->id;
}
Cart *User::getCart()
{
    return this->cart;
}
Membership *User::getMembership()
{
    return this->membership;
}
Membership *User::purchaseMembership(MEMBERSHIP_NAME name, PAYMENT_METHOD paymentMethod) {
    Membership* m = OrderManager::getInstance()->createMembershipOrder(this->id, name, paymentMethod);
    this->membership = m;
    return m;
}
Review *User::writeReview(string txt, double ratings, int bookId) {
    Review* review = new Review(this->id, bookId, txt, ratings);
    this->reviews.push_back(review);
    BookStore::getInstance()->getBookById(bookId)->addReview(review);
    return review;
}
PurchaseOrder *User::purchaseBooks(PAYMENT_METHOD paymentMethod, pair<int, int> address) {
    PurchaseOrder* order = OrderManager::getInstance()->createPurchaseOrder(this->id, cart->getBooks(), cart->getCost(), address, paymentMethod);
    this->purchaseOrders.push_back(order);
    this->cart->clearCart();
    return order;
}
LendingOrder *User::lendBooks(PAYMENT_METHOD paymentMethod, pair<int, int> address, int numberOfDays) {
    if (this->membership == nullptr || this->membership->isActive() == false) {
        cout << "either buy a membership or renew your membership" << endl;
        return nullptr;
    }
    LendingOrder* order = OrderManager::getInstance()->createLendingOrder(this->id, cart->getBooks(), cart->getCost(), address, numberOfDays, paymentMethod);
    this->lendingOrders.push_back(order);
    this->cart->clearCart();
    return order;
}
void User::cancelPurchaseOrder(PurchaseOrder *order) {
    OrderManager::getInstance()->updatePurchaseOrderStatus(order->getId(), PURCHASE_ORDER_STATUS::CANCELLED);
}
void User::cancelLendingOrder(LendingOrder *order) {
    OrderManager::getInstance()->updateLendingOrderStatus(order->getId(), LENDING_ORDER_STATUS::CANCELLED_LENDING_ORDER);
}
void User::returnBooks(LendingOrder *order) {
    OrderManager::getInstance()->updateLendingOrderStatus(order->getId(), LENDING_ORDER_STATUS::RETURN_REQUEST_RECEIVED);
}
void User::renewMembership() {
    OrderManager::getInstance()->renewMembership(this->membership->getId(), PAYMENT_METHOD::CARD);
}