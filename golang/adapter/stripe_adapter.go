package main

type StripeAdapter struct {
	stripe *Stripe
}

// constructor function
func NewStripeAdapter(stripe *Stripe) *StripeAdapter {
	return &StripeAdapter{
		stripe,
	}
}

func (stripeAdapter *StripeAdapter) pay(amount int) {
	stripeAdapter.stripe.charge(amount)
}
