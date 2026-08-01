package main

type PaymentServiceProviderRoutingStrategy interface {
	Route(OrderId string, Amount int, Currency string, PaymentId string) *CheckoutResponse
}
