#pragma once

#include "common.hpp"

class Membership;
class Cart;
class Review;
class PurchaseOrder;
class LendingOrder;

class User {
    private:
        int id;
        string name;
        string phone;
        Cart* cart;
        Membership* membership;
        vector<PurchaseOrder*> purchaseOrders;
        vector<LendingOrder*> lendingOrders;
        vector<Review*> reviews;
    public:
        User(int id, string name, string phone);
        int getId();
        Cart* getCart();
        Membership* getMembership();
        Membership* purchaseMembership(MEMBERSHIP_NAME name, PAYMENT_METHOD paymentMethod);
        Review* writeReview(string txt, double ratings, int bookId);
        PurchaseOrder* purchaseBooks(PAYMENT_METHOD paymentMethod, pair<int, int> address);
        LendingOrder* lendBooks(PAYMENT_METHOD paymentMethod, pair<int, int> address, int numberOfDays);
        void cancelPurchaseOrder(PurchaseOrder* order);
        void cancelLendingOrder(LendingOrder* order);
        void returnBooks(LendingOrder* order);
        void renewMembership();
};