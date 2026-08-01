package main

type WebhookResponse struct {
	PaymentStatus      PAYMENT_STATUS
	OrderId            string
	CheckoutResponseId string
	PaymentId          string
}

func NewWebhookResponse(OrderId string, CheckoutResponseId string, PaymentStatus PAYMENT_STATUS, PaymentId string) *WebhookResponse {
	return &WebhookResponse{
		PaymentStatus,
		OrderId,
		CheckoutResponseId,
		PaymentId,
	}
}
