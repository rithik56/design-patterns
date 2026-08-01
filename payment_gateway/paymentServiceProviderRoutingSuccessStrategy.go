package main

type PaymentServiceProviderRoutingSuccessStrategy struct {
	PaymentMetricsTracker         *PaymentMetricsTracker
	PaymentServiceProviderFactory *PaymentServiceProviderFactory
}

func NewPaymentServiceProviderRoutingSuccessStrategy(PaymentMetricsTracker *PaymentMetricsTracker, PaymentServiceProviderFactory *PaymentServiceProviderFactory) *PaymentServiceProviderRoutingSuccessStrategy {
	return &PaymentServiceProviderRoutingSuccessStrategy{
		PaymentMetricsTracker,
		PaymentServiceProviderFactory,
	}
}

func (p *PaymentServiceProviderRoutingSuccessStrategy) Route(OrderId string, Amount int, Currency string, PaymentId string) *CheckoutResponse {
	paymentServiceProviders := p.PaymentServiceProviderFactory.GetPaymentServiceProviders()
	provider := paymentServiceProviders[0]
	highestSuccessRate := p.PaymentMetricsTracker.GetSuccessRate(provider.GetId())
	for _, prov := range paymentServiceProviders {
		currSuccessRate := p.PaymentMetricsTracker.GetSuccessRate(prov.GetId())
		if currSuccessRate > highestSuccessRate {
			highestSuccessRate = currSuccessRate
			provider = prov
		}
	}
	return provider.CreateIntent(OrderId, Amount, Currency, PaymentId)
}
