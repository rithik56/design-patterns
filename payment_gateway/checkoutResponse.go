package main

type CheckoutResponse struct {
	PaymentStatus            PAYMENT_STATUS
	CheckoutResponseId       string
	OrderId                  string
	Amount                   int
	Curr                     string
	PaymentId                string
	PaymentServiceProviderId string
}

func NewCheckoutResponse(CheckoutResponseId string, OrderId string, PaymentId string, Amount int, Curr string, PaymentServiceProviderId string) *CheckoutResponse {
	return &CheckoutResponse{
		CheckoutResponseId:       CheckoutResponseId,
		OrderId:                  OrderId,
		PaymentId:                PaymentId,
		Amount:                   Amount,
		Curr:                     Curr,
		PaymentStatus:            PaymentStatusPending,
		PaymentServiceProviderId: PaymentServiceProviderId,
	}
}
