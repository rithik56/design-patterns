package main

type PaymentService struct {
	Payments map[string]*Payment
}

func NewPaymentService() *PaymentService {
	return &PaymentService{
		Payments: make(map[string]*Payment),
	}
}

func (o *PaymentService) createPayment(Amount int, Currency string, OrderId string) *Payment {
	newPayment := NewPayment(Amount, Currency, OrderId)
	o.Payments[newPayment.PaymentId] = newPayment
	return newPayment
}
