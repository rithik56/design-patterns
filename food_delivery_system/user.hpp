#pragma once

#include "common.hpp"
#include "location.hpp"
#include "cart.hpp"
#include "dish.hpp"
#include "restaurant.hpp"
#include "membership.hpp"
#include "complaint.hpp"

class Order;
class Membership;

class User {
    protected:
        int id;
        string name;
        string phoneNumber;
        Location* address;
        Cart* cart;
        Membership* membership;
        vector<Order*> orderHistory;
        vector<Complaint*> complaintHistory;
    public:
        User(int id, string name, string phoneNumber, Location* address);
        int getId();
        Membership* getMembership();
        void setMembership(Membership* membership);
        string getName();
        string getPhoneNumber();
        Location* getAddress();
        void addToCart(Dish* dish, Restaurant* restaurant);
        void removeFromCart(Dish* dish);
        Order* placeOrder();
        Complaint* registerCompaint(Order* order, string query);
        void showOrderHistory();
        void showComplaintHistory();
        void showMembershipDetails();
        bool isEligibleForFreeDelivery(Cart* cart);
        void buyMembership(MEMBERSHIP_ENUM name);
};