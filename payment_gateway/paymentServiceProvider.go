package main

type PaymentServiceProvider interface {
	GetId() string
	CreateIntent(OrderId string, Amount int, Currency string, PaymentId string) *CheckoutResponse
	ParseWebhook(request *RawWebhookRequest) *WebhookResponse
	CheckPaymentStatus(CheckoutResponseId string) PAYMENT_STATUS
}
