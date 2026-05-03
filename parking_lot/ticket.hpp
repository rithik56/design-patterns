#pragma once

#include "common.hpp"
#include "slot.hpp"
#include "vehicle.hpp"
#include "payment.hpp"

class ParkingManager;

class Ticket {
    private:
        int ticketNumber;
        Slot* slot;
        Payment* payment;
        Vehicle* vehicle;
        long long int entryTimestamp;
        long long int exitTimestamp;
        int parkingFee;
    public:
        Ticket(int ticketNumber, Slot* slot, Vehicle* vehicle);
        void processPayment(PAYMENT_MODE paymentMode);
        int getTicketNumber();
        double getPaymentAmount();
        PAYMENT_STATUS getPaymentStatus();
        Slot* getSlot();
        friend ParkingManager;
};