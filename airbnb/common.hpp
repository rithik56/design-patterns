#pragma once

#include<iostream>
using namespace std;

enum BOOKING_STATUS {
    PENDING,
    ACCEPTED,
    REJECTED,
    AVAILABLE,
    CHECK_IN,
    CHECK_OUT,
};

enum PAYMENT_STATUS {
    PAYMENT_PENDING,
    PAYMENT_PROCESSING,
    PAYMENT_SUCCESSFUL
};

enum PROPERTY_TYPE {
    FLAT,
    VILLA
};

enum PROPERTY_SUB_TYPE {
    SINGLE_UNIT,
    ENTIRE_UNIT
};

extern int newUserId;
extern int newGuestReviewId;
extern int newHostReviewId;
extern int newPropertyReviewId;
extern int newChatId;
extern int newBookingId;
extern int newPaymentId;
extern int newPropertyId;
extern int newHostId;