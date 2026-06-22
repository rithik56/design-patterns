#pragma once

#include "common.hpp"

class PurchaseOrder;
class LendingOrder;
class Membership;
class MembershipOrder;
class Book;

class OrderManager {
    private:
        OrderManager();
        static OrderManager* instance;
        static mutex mtx;
        unordered_map<int, MembershipOrder*> membershipOrders;
        unordered_map<int, PurchaseOrder*> purchaseOrders;
        unordered_map<int, LendingOrder*> lendingOrders;
    public:
        static OrderManager* getInstance();
        Membership* createMembershipOrder(int userId, MEMBERSHIP_NAME name, PAYMENT_METHOD paymentMethod);
        void renewMembership(int membershipId, PAYMENT_METHOD paymentMethod);
        LendingOrder* createLendingOrder(int userId, unordered_map<Book*, int> books, double itemsCost, pair<int, int> address, int numberOfDays, PAYMENT_METHOD paymentMethod);
        PurchaseOrder* createPurchaseOrder(int userId, unordered_map<Book*, int> books, double itemsCost, pair<int, int> address, PAYMENT_METHOD paymentMethod);
        void updateLendingOrderStatus(int order_id, LENDING_ORDER_STATUS status);
        void updatePurchaseOrderStatus(int order_id, PURCHASE_ORDER_STATUS status);
};