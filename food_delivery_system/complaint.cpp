#include "complaint.hpp"
#include "order.hpp"

Complaint::Complaint(int id, Order *order, string query, COMPLAINT_TYPE type)
{
    this->id = id;
    this->order = order;
    this->query = query;
    this->type = type;
    this->complaintStatus = COMPLAINT_STATUS::OPEN;
}
COMPLAINT_TYPE Complaint::getType()
{
    return this->type;
}
Order *Complaint::getOrder()
{
    return this->order;
}
COMPLAINT_STATUS Complaint::getStatus()
{
    return this->complaintStatus;
}
void Complaint::setStatus(COMPLAINT_STATUS complaintStatus)
{
    this->complaintStatus = complaintStatus;
}

void Complaint::showDetails() {
    cout << "Complaint Details " << endl;
    cout << "Order Id : " << this->order->getId() << endl;
    cout << "Query: " << this->query << endl;
    cout << "Status: " << this->complaintStatus << endl;
    cout << "Type: " << this->type << endl;
}