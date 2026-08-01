package main

import (
	"encoding/json"
	"math/rand"

	"github.com/google/uuid"
)

type RazorpayWebhookPayload struct {
	Event       string
	ReferenceId string
	Notes       map[string]string
	Id          string
}

var razorpayEventsToStatus = map[string]PAYMENT_STATUS{
	"payment.authorized": PaymentStatusPending,
	"payment.captured":   PaymentStatusSuccess,
	"payment.failed":     PaymentStatusFailed,
	"order.paid":         PaymentStatusSuccess,
}

type RazorpayServiceProviderAdapter struct {
	Id              string
	WebhookProducer *WebhookProducer
	PaymentService  *PaymentService
}

func NewRazorpayWebhookPayload(Event string, ReferenceId string, Notes map[string]string, Id string) *RazorpayWebhookPayload {
	return &RazorpayWebhookPayload{
		Event,
		ReferenceId,
		Notes,
		Id,
	}
}

func NewRazorpayServiceProviderAdapter(Id string, WebhookProducer *WebhookProducer, PaymentService *PaymentService) *RazorpayServiceProviderAdapter {
	return &RazorpayServiceProviderAdapter{
		Id,
		WebhookProducer,
		PaymentService,
	}
}

func (r *RazorpayServiceProviderAdapter) GetId() string {
	return r.Id
}

func (r *RazorpayServiceProviderAdapter) CreateIntent(OrderId string, Amount int, Currency string, PaymentId string) *CheckoutResponse {
	CheckoutResponseId := "razorpay_" + uuid.New().String()
	payment := r.PaymentService.Payments[PaymentId]
	payment.CheckoutResponseId = CheckoutResponseId
	payment.PaymentServiceProviderId = r.Id
	return NewCheckoutResponse(CheckoutResponseId, OrderId, PaymentId, Amount, Currency, r.Id)
}

func (r *RazorpayServiceProviderAdapter) ParseWebhook(request *RawWebhookRequest) *WebhookResponse {
	var jsonPayload RazorpayWebhookPayload
	json.Unmarshal([]byte(request.Body), &jsonPayload)
	return NewWebhookResponse(jsonPayload.ReferenceId, jsonPayload.Id, razorpayEventsToStatus[jsonPayload.Event], jsonPayload.Notes["PaymentId"])
}

func (r *RazorpayServiceProviderAdapter) CheckPaymentStatus(CheckoutResponseId string) PAYMENT_STATUS {
	if rand.Intn(2) == 1 {
		return PaymentStatusSuccess
	}
	return PaymentStatusFailed
}
