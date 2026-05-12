#include "user.hpp"
#include "order.hpp"
#include "orderManager.hpp"

User::User(int id, string name)
{
    this->id = id;
    this->name = name;
    this->cart = new Cart();
}
int User::getId()
{
    return this->id;
}
string User::getName()
{
    return this->name;
}
        void User::addItem(Item* item, Restaurant* restaurant) {
            this->cart->addItem(item, restaurant);
        }
        void User::removeItem(Item* item) {
            this->cart->removeItem(item);
        }
Order *User::placeOrder()
{   
    Order* order = OrderManager::getInstance()->placeOrder(this, this->cart);
    this->cart = new Cart();
    this->orderHistory.push_back(order);
    return order;
}
void User::showOrderHistory()
{
    for (int i = 0; i < this->orderHistory.size(); i++) {
        cout << "Restaurant Name: " << this->orderHistory[i]->getRestaurant()->getName() << endl;
        cout << "Items: " << endl;
        for (auto it = this->orderHistory[i]->getItems().begin(); it != this->orderHistory[i]->getItems().end(); it++) {
            cout << "Item Name: " << it->first->getName() << endl;
            cout << "Item Price: " << it->first->getPrice() << endl;
            cout << "Quantity: " << it->second << endl;
        }
        cout << "Total Amount: " << this->orderHistory[i]->getPayment()->getAmount() << endl;
        cout << "Order Status: " << orderStatus[this->orderHistory[i]->getOrderStatus()] << endl;
        cout << "Payment Status: " << paymentStatus[this->orderHistory[i]->getPayment()->getStatus()] << endl;
    }
}