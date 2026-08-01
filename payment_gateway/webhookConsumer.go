package main

import (
	"fmt"
)

type WebhookConsumer struct {
	PaymentStatusUpdateService *PaymentStatusUpdateService
}

func NewWebhookConsumer(PaymentStatusUpdateService *PaymentStatusUpdateService) *WebhookConsumer {
	return &WebhookConsumer{}
}

func (w *WebhookConsumer) onMessage(event *WebhookResponse) {
	fmt.Println("consuming webhook events from message queue")
	w.PaymentStatusUpdateService.updateStatus(event.PaymentId, event.PaymentStatus)
}
