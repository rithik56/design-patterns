#include "user.hpp"
#include "order.hpp"
#include "cart.hpp"

User::User(int id, string name, string phone) {
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->cart = new Cart(this);
}

int User::getId() {
    return this->id;
}

string User::getName() {
    return this->name;
}

Location* User::getAddress() {
    return this->communicationAddress;
}

Cart* User::getCart() {
    return this->cart;
}

void User::placeOrder() {
    vector<Order*> orders = this->cart->getOrders();
    for (int i = 0; i < orders.size(); i++) {
        orders[i]->handleOrder();
        this->orderHistory.push_back(orders[i]);
    }
    this->cart->clearItems();
}

void User::updateCommunicationAddress(Location* communicationAddress) {
    this->communicationAddress = communicationAddress;
}

void User::showOrderHistory() {
    cout << "Order History" << endl;
    for (int i = 0; i < this->orderHistory.size(); i++) {
        cout << "Restaurant Name: " << this->orderHistory[i]->getRestaurantName() << endl;
        cout << "Items: " << endl;
        for (int j = 0; j < this->orderHistory[i]->getItems().size(); j++) {
           int freq = this->orderHistory[i]->getItems()[j].second;
           cout << this->orderHistory[i]->getItems()[j].first->getName() << " " << freq << endl;
        }
        cout << "Order Cost: " << this->orderHistory[i]->getPaymentAmount() << endl;
        cout << "Order Status: " << orderStatus[this->orderHistory[i]->getOrderStatus()] << endl;
        cout << "Payment Status: " << paymentStatus[this->orderHistory[i]->getPaymentStatus()] << endl;
        cout << endl;
    }
}
