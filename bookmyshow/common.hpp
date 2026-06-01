#pragma once

#include<iostream>
using namespace std;

enum SEAT_CATEGORY {
    NORMAL,
    PREMIUM,
    VIP
};

enum SEAT_STATUS {
    BOOKED,
    AVAILABLE
};

enum PAYMENT_STATUS {
    PENDING,
    IN_PROGRESS,
    SUCCESSFUL
};

enum BOOKING_STATUS {
    CANCELLED,
    SUCCESS
};

enum SHOW_STATUS {
    RUNNING,
    NOT_STARTED,
    FINISHED
};

extern int movieId;
extern int userId;
extern int bookingId;

extern const char* displaySeatCategory[];
extern const char* displaySeatStatus[];
extern const char* displayPaymentStatus[];
extern const char* displayBookingStatus[];
extern const char* displayShowStatus[];