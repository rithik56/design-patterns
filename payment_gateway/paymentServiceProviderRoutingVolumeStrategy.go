package main

import (
	"math/rand"
)

type PaymentServiceProviderRoutingVolumeStrategy struct {
	PaymentVolumeConfig           map[string]int
	PaymentServiceProviderFactory *PaymentServiceProviderFactory
}

func NewPaymentServiceProviderRoutingVolumeStrategy(PaymentVolumeConfig map[string]int, PaymentServiceProviderFactory *PaymentServiceProviderFactory) *PaymentServiceProviderRoutingVolumeStrategy {
	return &PaymentServiceProviderRoutingVolumeStrategy{
		PaymentVolumeConfig,
		PaymentServiceProviderFactory,
	}
}

func (p *PaymentServiceProviderRoutingVolumeStrategy) Route(OrderId string, Amount int, Currency string, PaymentId string) *CheckoutResponse {
	providers := p.PaymentServiceProviderFactory.GetPaymentServiceProviders()
	r := rand.Intn(100)
	cumulative := 0
	var finalProvider PaymentServiceProvider
	for _, provider := range providers {
		cumulative += p.PaymentVolumeConfig[provider.GetId()]
		if r < cumulative {
			finalProvider = provider
			break
		}
	}
	return finalProvider.CreateIntent(OrderId, Amount, Currency, PaymentId)
}
