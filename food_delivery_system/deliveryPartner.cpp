#include "deliveryPartner.hpp"
#include "orderManager.hpp"
#include "order.hpp"
#include "user.hpp"
#include "complaintManager.hpp"
        
DeliveryPartner::DeliveryPartner(int id, string name, Location* currLocation, string phoneNumber) {
    this->id = id;
    this->name = name;
    this->currLocation = currLocation;
    this->phoneNumber = phoneNumber;
    this->status = DRIVER_STATUS::NOT_AVAILABLE;
}
        
DRIVER_STATUS DeliveryPartner::getStatus() {
    return this->status;
}   
        
Location* DeliveryPartner::getCurrLocation() {
    return this->currLocation;
}
        
void DeliveryPartner::startDelivery(Order* order) {
    OrderManager::getInstance()->updateOrderStatus(order, ORDER_STATUS::DELIVERY_IN_PROGRESS);
}

void DeliveryPartner::completeDelivery(Order* order) {
    OrderManager::getInstance()->updateOrderStatus(order, ORDER_STATUS::DELIVERY_SUCCESSFUL);
    this->currLocation = order->getCart()->getUser()->getAddress();
}

void DeliveryPartner::showDetails() {
    cout << "Delivery Partner Details: " << endl;
    cout << "Name: " << this->name << endl;
}

void DeliveryPartner::setStatus(DRIVER_STATUS status) {
    this->status = status;
}

void DeliveryPartner::setCurrLocation(Location* currLocation) {
    this->currLocation = currLocation;
}

 Complaint* DeliveryPartner::registerCompaint(Order* order, string query) {
    Complaint* complaint = ComplaintManager::getInstance()->addComplaint(order, query, COMPLAINT_TYPE::DELIVERY_PARTNER);
    this->complaintHistory.push_back(complaint);
    order->addComplaint(complaint);
    return complaint;
 }
        
 
 void DeliveryPartner::showComplaintHistory() {
        for (int i = 0; i < this->complaintHistory.size(); i++) {
        this->complaintHistory[i]->showDetails();
    }
 }