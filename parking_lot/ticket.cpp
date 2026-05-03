#include "ticket.hpp"
#include "cardPayment.hpp"
#include "UPIPayment.hpp"
#include "cashPayment.hpp"
#include <ctime>

Ticket::Ticket(int ticketNumber, Slot* slot, Vehicle* vehicle) {
    this->ticketNumber = ticketNumber;
    this->slot = slot;
    this->payment = nullptr;
    this->vehicle = vehicle;
    time_t result = time(nullptr);
    this->entryTimestamp = result;
}

void Ticket::processPayment(PAYMENT_MODE paymentMode = PAYMENT_MODE::CASH) {
    Payment* payment;
    if (paymentMode == PAYMENT_MODE::CARD) {
        payment = new CardPayment(this->parkingFee);
    } else if (paymentMode == PAYMENT_MODE::UPI) {
        payment = new UPIPayment(this->parkingFee);
    } else {
        payment = new CashPayment(this->parkingFee);
    }
    this->payment = payment;
    payment->processPayment();
}

int Ticket::getTicketNumber() {
    return this->ticketNumber;
}

double Ticket::getPaymentAmount() {
    return this->payment->getAmount();
}

PAYMENT_STATUS Ticket::getPaymentStatus() {
    return this->payment->getStatus();
}

Slot* Ticket::getSlot() {
    return this->slot;
}
