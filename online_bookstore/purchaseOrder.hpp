#pragma once

#include "common.hpp"
#include "order.hpp"

class Book;

class PurchaseOrder: public Order {
    private:
        PURCHASE_ORDER_STATUS status;
    public:
        PurchaseOrder(int id, int userId, unordered_map<Book*, int> books, double itemsCost, int paymentId, pair<int, int> address);
        void setStatus(PURCHASE_ORDER_STATUS status);
};