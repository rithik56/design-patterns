package main

import (
	"encoding/json"
	"math/rand"

	"github.com/google/uuid"
)

type StripeWebhookPayload struct {
	Event    string
	Receipt  string
	Metadata map[string]string
	Id       string
}

var stripeEventsToStatus = map[string]PAYMENT_STATUS{
	"payment_intent.succeeded":       PaymentStatusSuccess,
	"payment_intent.payment_failed":  PaymentStatusFailed,
	"payment_intent.canceled":        PaymentStatusFailed,
	"payment_intent.processing":      PaymentStatusPending,
	"payment_intent.created":         PaymentStatusPending,
	"payment_intent.requires_action": PaymentStatusPending,
}

type StripeServiceProviderAdapter struct {
	Id              string
	WebhookProducer *WebhookProducer
	PaymentService  *PaymentService
}

func NewStripeWebhookPayload(Event string, Receipt string, Metadata map[string]string, Id string) *RazorpayWebhookPayload {
	return &RazorpayWebhookPayload{
		Event,
		Receipt,
		Metadata,
		Id,
	}
}

func NewStripeServiceProviderAdapter(Id string, WebhookProducer *WebhookProducer, PaymentService *PaymentService) *StripeServiceProviderAdapter {
	return &StripeServiceProviderAdapter{
		Id,
		WebhookProducer,
		PaymentService,
	}
}

func (s *StripeServiceProviderAdapter) GetId() string {
	return s.Id
}

func (s *StripeServiceProviderAdapter) CreateIntent(OrderId string, Amount int, Currency string, PaymentId string) *CheckoutResponse {
	CheckoutResponseId := "stripe_" + uuid.New().String()
	payment := s.PaymentService.Payments[PaymentId]
	payment.CheckoutResponseId = CheckoutResponseId
	payment.PaymentServiceProviderId = s.Id
	return NewCheckoutResponse(CheckoutResponseId, OrderId, PaymentId, Amount, Currency, s.Id)
}

func (s *StripeServiceProviderAdapter) ParseWebhook(request *RawWebhookRequest) *WebhookResponse {
	var jsonPayload StripeWebhookPayload
	json.Unmarshal([]byte(request.Body), &jsonPayload)
	return NewWebhookResponse(jsonPayload.Receipt, jsonPayload.Id, stripeEventsToStatus[jsonPayload.Event], jsonPayload.Metadata["PaymentId"])
}

func (s *StripeServiceProviderAdapter) CheckPaymentStatus(CheckoutResponseId string) PAYMENT_STATUS {
	if rand.Intn(2) == 1 {
		return PaymentStatusSuccess
	}
	return PaymentStatusFailed
}
