#include "purchaseOrder.hpp"

PurchaseOrder::PurchaseOrder(int id, int userId, unordered_map<Book*, int> books, double itemsCost, int paymentId, pair<int, int> address) : Order(id, userId, books, itemsCost, paymentId, address)
{
    this->status = PURCHASE_ORDER_STATUS::CREATED;
}
void PurchaseOrder::setStatus(PURCHASE_ORDER_STATUS status)
{
    this->status = status;
}