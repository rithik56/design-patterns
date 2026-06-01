#include "user.hpp"
#include "order.hpp"
#include "orderManager.hpp"
#include "membershipManager.hpp"
#include "membership.hpp"
#include "complaintManager.hpp"

User::User(int id, string name, string phoneNumber, Location *address)
{
    this->id = id;
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->cart = new Cart(this);
}

int User::getId()
{
    return this->id;
}

string User::getName()
{
    return this->name;
}

Membership *User::getMembership()
{
    return this->membership;
}
void User::setMembership(Membership *membership)
{
    this->membership = membership;
}

string User::getPhoneNumber()
{
    return this->phoneNumber;
}

Location *User::getAddress()
{
    return this->address;
}

void User::addToCart(Dish *dish, Restaurant *restaurant)
{
    this->cart->addDish(restaurant, dish);
}

void User::removeFromCart(Dish *dish)
{
    this->cart->removeDish(dish);
}

Order *User::placeOrder()
{
    Order *order = OrderManager::getInstance()->createOrder(this, this->cart);
    this->cart = new Cart(this);
    this->orderHistory.push_back(order);
    return order;
}

void User::showOrderHistory() {
    for (int i = 0; i < this->orderHistory.size(); i++) {
        this->orderHistory[i]->showOrderDetails();
    }
}

void User::showMembershipDetails() {
    this->membership->showMembershipDetails();
}

bool User::isEligibleForFreeDelivery(Cart* cart) {
    return this->membership && this->membership->isEligibleForFreeDelivery(cart);
}

void User::buyMembership(MEMBERSHIP_ENUM name) {
    this->membership = MembershipManager::getInstance()->addMembership(this, name);
}

void User::showComplaintHistory() {
    for (int i = 0; i < this->complaintHistory.size(); i++) {
        this->complaintHistory[i]->showDetails();
    }
}

Complaint* User::registerCompaint(Order* order, string query) {
    Complaint* complaint = ComplaintManager::getInstance()->addComplaint(order, query, COMPLAINT_TYPE::CUSTOMER);
    this->complaintHistory.push_back(complaint);
    order->addComplaint(complaint);
    return complaint;
}