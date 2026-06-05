#include "paymentRequest.hpp"

PaymentRequest::PaymentRequest(int id, FundAccount *receiver, Amount *amount, Wallet *sender)
{
    this->id = id;
    this->receiver = receiver;
    this->amount = amount;
    this->sender = sender;
    this->status = PAYMENT_REQUEST_STATUS::NOT_PAID;
}
int PaymentRequest::getId()
{
    return this->id;
}
FundAccount *PaymentRequest::getReceiver()
{
    return this->receiver;
}
Amount *PaymentRequest::getAmount()
{
    return this->amount;
}
Wallet *PaymentRequest::getSender()
{
    return this->sender;
}
PAYMENT_REQUEST_STATUS PaymentRequest::getStatus()
{
    return this->status;
}
void PaymentRequest::setStatus(PAYMENT_REQUEST_STATUS status)
{
    this->status = status;
}