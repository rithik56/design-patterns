package main

import (
	"encoding/json"
	"fmt"
)

func main() {
	paymentService := NewPaymentService()
	orderService := NewOrderService(paymentService)
	order1Products := map[string]int{
		"sku_123": 2,
		"sku_456": 1,
	}
	order1 := orderService.createOrder(1000, "INR", order1Products)
	webhookProducer := NewWebhookProducer()
	razorpayPaymentServiceProvider := NewRazorpayServiceProviderAdapter("razorpay", webhookProducer, paymentService)
	stripePaymentServiceProvider := NewStripeServiceProviderAdapter("stripe", webhookProducer, paymentService)
	paymentServiceProviders := map[string]PaymentServiceProvider{
		"razorpay": razorpayPaymentServiceProvider,
		"stripe":   stripePaymentServiceProvider,
	}
	paymentServiceProviderFactory := NewPaymentServiceProviderFactory(paymentServiceProviders)
	successRoutingStrategy := NewPaymentServiceProviderRoutingSuccessStrategy(NewPaymentMetricsTracker(), paymentServiceProviderFactory)
	// volumeConfig := map[string]int{
	// 	"razorpay": 70,
	// 	"stripe":   30,
	// }
	// volumeRoutingStrategy := NewPaymentServiceProviderRoutingVolumeStrategy(volumeConfig, paymentServiceProviderFactory)
	paymentGatewayOrchestrator := NewPaymentGatewayOrchestrator(successRoutingStrategy)
	order1CheckoutResponse := paymentGatewayOrchestrator.Route(order1.OrderId, order1.Amount, order1.Currency, order1.PaymentAttempts[len(order1.PaymentAttempts)-1].PaymentId)
	fmt.Println("order1_checkout_response", order1CheckoutResponse)
	var psp PaymentServiceProvider
	var webhookResponse *WebhookResponse
	var rawWebhookRequest *RawWebhookRequest
	psp = paymentServiceProviderFactory.GetPaymentServiceProviderById(order1CheckoutResponse.PaymentServiceProviderId)
	if psp.GetId() == "razorpay" {
		Notes := map[string]string{
			"PaymentId": order1CheckoutResponse.PaymentId,
		}
		body, _ := json.Marshal(NewRazorpayWebhookPayload("order.paid", order1CheckoutResponse.OrderId, Notes, order1CheckoutResponse.CheckoutResponseId))
		headers := map[string]string{
			"razorpay-signature-header": "signature-key",
		}
		rawWebhookRequest = NewRawWebhookRequest(body, headers, "")
	} else {
		Metadata := map[string]string{
			"PaymentId": order1CheckoutResponse.PaymentId,
		}
		body, _ := json.Marshal(NewStripeWebhookPayload("payment_intent.succeeded", order1CheckoutResponse.OrderId, Metadata, order1CheckoutResponse.CheckoutResponseId))
		headers := map[string]string{
			"stripe-signature-header": "signature-key",
		}
		rawWebhookRequest = NewRawWebhookRequest(body, headers, "")
	}
	webhookResponse = psp.ParseWebhook(rawWebhookRequest)
	paymentRetryService := NewPaymentRetryService(5, paymentGatewayOrchestrator, orderService, paymentService)
	emailNotification := NewEmailNotification()
	smsNotification := NewSmsNotification()
	notificationFactory := NewNotificationFactory(map[NOTIFICATION_CHANNEL]NotificationChannel{
		NotificationChannelEmail: emailNotification,
		NotificationChannelSms:   smsNotification,
	})
	notificationService := NewNotificationService(notificationFactory)
	paymentMetricsTrackerService := NewPaymentMetricsTracker()
	paymentStatusUpdateService := NewPaymentStatusUpdateService(paymentService, orderService, paymentRetryService, notificationService, paymentMetricsTrackerService)
	webhookConsumer := NewWebhookConsumer(paymentStatusUpdateService)
	webhookConsumer.onMessage(webhookResponse)
	// order 1 details &{b3a23661-c61d-4edb-a705-23b28c752bc6 1000 INR PAYMENT_SUCCESS [0x38a3eca32090] 30/07/2026 30/07/2026 map[sku_123:2 sku_456:1]}
	fmt.Println("order 1 details", order1)
}
