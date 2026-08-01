package main

import (
	"fmt"
)

type WebhookProducer struct {
}

func NewWebhookProducer() *WebhookProducer {
	return &WebhookProducer{}
}

func (w *WebhookProducer) Publish(response *WebhookResponse) {
	fmt.Println("publishing webhook events to message queue")
}
