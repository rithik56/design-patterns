#include "orderManager.hpp"
#include "lendingOrder.hpp"
#include "purchaseOrder.hpp"
#include "bookStore.hpp"
#include "paymentService.hpp"
#include "membershipFactory.hpp"
#include "membershipOrder.hpp"
#include "membership.hpp"
#include "paymentMethod.hpp"

OrderManager *OrderManager::getInstance()
{
    if (instance == NULL)
    {
        mtx.lock();
        if (instance == NULL)
        {
            instance = new OrderManager();
        }
        mtx.unlock();
    }
    return instance;
}

OrderManager *OrderManager::instance = nullptr;
mutex OrderManager::mtx;

OrderManager::OrderManager() {

}

LendingOrder *OrderManager::createLendingOrder(int userId, unordered_map<Book*, int> books, double itemsCost, pair<int, int> address, int numberOfDays, PAYMENT_METHOD paymentMethod)
{
    double lendingCost = 0.3 * itemsCost;
    PaymentMethod* p = PaymentService::getInstance()->handlePayment(lendingCost, paymentMethod);
    LendingOrder* order = new LendingOrder(lendingOrderId++, userId, books, itemsCost, p->getId(), address, numberOfDays, "17/06/2026", "17/07/2026", paymentMethod);
    BookStore::getInstance()->handlePurchaseBooks(order->getBooks());
    order->addPayment(p->getId());
    this->lendingOrders[order->getId()] = order;
    return order;
}

PurchaseOrder *OrderManager::createPurchaseOrder(int userId, unordered_map<Book*, int> books, double itemsCost, pair<int, int> address, PAYMENT_METHOD paymentMethod)
{
    double purchaseCost = 1.18 * itemsCost;
    PaymentMethod* p = PaymentService::getInstance()->handlePayment(purchaseCost, paymentMethod);
    PurchaseOrder* order = new PurchaseOrder(purchaseOrderId++, userId, books, itemsCost, p->getId(), address);
    BookStore::getInstance()->handlePurchaseBooks(order->getBooks());
    order->addPayment(p->getId());
    this->purchaseOrders[order->getId()] = order;
    return order;
}

void OrderManager::updateLendingOrderStatus(int order_id, LENDING_ORDER_STATUS status)
{
    LendingOrder *order = this->lendingOrders[order_id];
    if (status == LENDING_ORDER_STATUS::RETURNED_TO_BOOKSTORE)
    {
        BookStore::getInstance()->handleReturnBooks(order->getBooks());
    } else if (status == LENDING_ORDER_STATUS::RETURN_REQUEST_RECEIVED) {
        double fine = order->calculateFine();
        if (fine) {
            PaymentMethod* p = PaymentService::getInstance()->handlePayment(fine, order->getPaymentMethod());
            order->addPayment(p->getId());
        }
    } else if (status == LENDING_ORDER_STATUS::CANCELLED_LENDING_ORDER) {
        // initiate refund and add books to book store
        PaymentService::getInstance()->handleRefund(order->getPaymentId());
        BookStore::getInstance()->handleReturnBooks(order->getBooks());
    }
    order->setStatus(status);
}

void OrderManager::updatePurchaseOrderStatus(int order_id, PURCHASE_ORDER_STATUS status)
{
    PurchaseOrder *order = this->purchaseOrders[order_id];
    if (status == PURCHASE_ORDER_STATUS::CANCELLED) {
        // initiate refund and add books to book store
        PaymentService::getInstance()->handleRefund(order->getPaymentId());
        BookStore::getInstance()->handleReturnBooks(order->getBooks());
    }
    order->setStatus(status);
}

Membership* OrderManager::createMembershipOrder(int userId, MEMBERSHIP_NAME name, PAYMENT_METHOD paymentMethod) {
    Membership* m = MembershipFactory::getInstance()->createMembership(name);
    PaymentMethod* p = PaymentService::getInstance()->handlePayment(m->getCost(), paymentMethod);
    MembershipOrder* order = new MembershipOrder(membershipOrderId++, userId, m->getId(), p->getId());
    this->membershipOrders[order->getId()] = order;
    m->addPayment(p);
    return m;
}

void OrderManager::renewMembership(int membershipId, PAYMENT_METHOD paymentMethod) {
    Membership* m = MembershipFactory::getInstance()->getMembershipById(membershipId);
    PaymentMethod* p = PaymentService::getInstance()->handlePayment(m->getCost(), paymentMethod);
    m->addPayment(p);
    m->renew();
}