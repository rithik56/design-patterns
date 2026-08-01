package main

type PaymentGatewayOrchestrator struct {
	RoutingStrategy PaymentServiceProviderRoutingStrategy
}

func NewPaymentGatewayOrchestrator(RoutingStrategy PaymentServiceProviderRoutingStrategy) *PaymentGatewayOrchestrator {
	return &PaymentGatewayOrchestrator{
		RoutingStrategy: RoutingStrategy,
	}
}

func (p *PaymentGatewayOrchestrator) Route(OrderId string, Amount int, Currency string, PaymentId string) *CheckoutResponse {
	return p.RoutingStrategy.Route(OrderId, Amount, Currency, PaymentId)
}
