#pragma once

#include<iostream>
using namespace std;

enum GENRE_TYPE {
    ROMANTIC,
    DOCUMENTARY,
    SELF_HELP,
    BUSINESS,
    SPORTS,
    MATHEMATICS,
    SCIENCE
};

enum LENDING_ORDER_STATUS {
    CREATED_LENDING_ORDER,
    CANCELLED_LENDING_ORDER,
    READY_FOR_DELIVERY_LENDING_ORDER,
    OUT_FOR_DELIVERY_LENDING_ORDER,
    DELIVERED_LENDING_ORDER,
    RETURN_REQUEST_RECEIVED,
    OUT_FOR_RETURN,
    RETURNED,
    OUT_FOR_BOOKSTORE_DELIVERY,
    RETURNED_TO_BOOKSTORE
};

enum PURCHASE_ORDER_STATUS {
    CREATED,
    CANCELLED,
    READY_FOR_DELIVERY,
    OUT_FOR_DELIVERY,
    DELIVERED,
};

enum MEMBERSHIP_NAME {
    MONTHLY,
    ANNUAL
};

enum PAYMENT_STATUS {
    PENDING,
    IN_PROGRESS,
    SUCCESSFUL,
    FAILED,
    REFUND_PENDING,
    REFUND_IN_PROGRESS,
    REFUND_FAILED,
    REFUND_SUCCESS
};

enum PAYMENT_METHOD {
    UPI,
    CARD
};

extern int bookId;
extern int userId;
extern int paymentId;
extern int purchaseOrderId;
extern int lendingOrderId;
extern int membershipId;
extern int membershipOrderId;
extern int reviewId;