package main

func main() {
	var paymentProcesser PaymentProcessor
	var currentPaymentProcessor string = "stripe"

	if currentPaymentProcessor == "stripe" {
		paymentProcesser = NewStripeAdapter(&Stripe{})
	} else {
		paymentProcesser = &CurrentPaymentProcessor{}
	}

	paymentProcesser.pay(60)
}
