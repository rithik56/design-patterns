#pragma once

#include<iostream>
using namespace std;

extern int newUserId;
extern int newRestaurantId;
extern int newPaymentId;
extern int newOrderId;
extern int newDishId;
extern int newDeliveryPartnerId;
extern int newComplaintId;
extern int newMembershipId;

enum DRIVER_STATUS {
    NOT_AVAILABLE,
    AVAILABLE,
    BUSY
};

enum RESTAURANT_STATUS {
    OPEN_FOR_DELIVERY,
    CLOSED_FOR_DELIVERY
};

enum PAYMENT_STATUS {
    PAYMENT_PENDING,
    PAYMENT_PROCESSING,
    PAYMENT_SUCCESSFUL
};

enum ORDER_STATUS {
    PLACED,
    ACCEPTED,
    REJECTED,
    NOT_ASSIGNED,
    ASSIGNED,
    DELIVERY_IN_PROGRESS,
    DELIVERY_SUCCESSFUL
};

enum COMPLAINT_STATUS {
    OPEN,
    CLOSED
};

enum COMPLAINT_TYPE {
    CUSTOMER,
    DELIVERY_PARTNER
};

enum MEMBERSHIP_ENUM {
    GOLD
};