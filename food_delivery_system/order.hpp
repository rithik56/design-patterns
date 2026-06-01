#pragma once

#include "common.hpp"
#include "cart.hpp"
#include "payment.hpp"

class User;
class DeliveryPartner;
class Complaint;

class Order {
    private:
        int id;
        User* user;
        Cart* cart;
        DeliveryPartner* deliveryPartner;
        Payment* payment;
        ORDER_STATUS status;
        vector<Complaint*> complaints;
    public:
        Order(int id, User* user, Cart* cart);
        int getId();
        Cart* getCart();
        DeliveryPartner* getDeliveryPartner();
        void setDeliveryPartner(DeliveryPartner* deliveryPartner);
        Payment* getPayment();
        ORDER_STATUS getStatus();
        void setStatus(ORDER_STATUS status);
        void showOrderDetails();
        void showComplaints();
        void addComplaint(Complaint* complaint);
};