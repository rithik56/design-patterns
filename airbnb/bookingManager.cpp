#include "booking.hpp"
#include "property.hpp"
#include "bookingManager.hpp"
#include "paymentManager.hpp"
#include "user.hpp"
#include "host.hpp"

BookingManager* BookingManager::instance = NULL;
mutex BookingManager::mtx;

BookingManager::BookingManager() {

}

BookingManager* BookingManager::getInstance() {
    if (instance == NULL) {
        mtx.lock();
        if (instance == NULL) {
            instance = new BookingManager();
        }
        mtx.unlock();
    }
    return instance;
}

Booking* BookingManager::createBooking(User* guest, Property* property, int numberOfGuests, string startDate, string endDate) {
    int bookingId = newBookingId++;
    Payment* payment = PaymentManager::getInstance()->addPayment(property->getPrice());
    Booking* booking = new Booking(bookingId, guest, property, payment, numberOfGuests, startDate, endDate);
    this->mp[bookingId] = booking; 
    guest->addBooking(booking);
    property->addBooking(booking);
    property->getHost()->addBooking(booking);
    return booking;
}

void BookingManager::updateBookingStatus(Booking* booking, BOOKING_STATUS status) {
    if (status == BOOKING_STATUS::REJECTED) {
        booking->getProperty()->openData(booking->getStartDate());
    }
    booking->setBookingStatus(status);
}