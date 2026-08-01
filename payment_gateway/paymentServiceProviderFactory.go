package main

type PaymentServiceProviderFactory struct {
	PaymentServiceProviders map[string]PaymentServiceProvider
}

func NewPaymentServiceProviderFactory(PaymentServiceProviders map[string]PaymentServiceProvider) *PaymentServiceProviderFactory {
	return &PaymentServiceProviderFactory{
		PaymentServiceProviders,
	}
}

func (p *PaymentServiceProviderFactory) GetPaymentServiceProviders() []PaymentServiceProvider {
	providers := []PaymentServiceProvider{}
	for _, provider := range p.PaymentServiceProviders {
		providers = append(providers, provider)
	}
	return providers
}

func (p *PaymentServiceProviderFactory) GetPaymentServiceProviderById(PaymentServiceProviderId string) PaymentServiceProvider {
	provider, ok := p.PaymentServiceProviders[PaymentServiceProviderId]
	if ok {
		return provider
	}
	return nil
}
