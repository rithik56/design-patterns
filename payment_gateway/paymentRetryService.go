package main

type PaymentRetryService struct {
	MaxAttempts                int
	PaymentGatewayOrchestrator *PaymentGatewayOrchestrator
	OrderService               *OrderService
	PaymentService             *PaymentService
}

func NewPaymentRetryService(MaxAttempts int, PaymentGatewayOrchestrator *PaymentGatewayOrchestrator, OrderService *OrderService, PaymentService *PaymentService) *PaymentRetryService {
	return &PaymentRetryService{
		MaxAttempts:                MaxAttempts,
		PaymentGatewayOrchestrator: PaymentGatewayOrchestrator,
		OrderService:               OrderService,
		PaymentService:             PaymentService,
	}
}

func (p *PaymentRetryService) retryPayment(Payment *Payment) {
	order := p.OrderService.Orders[Payment.OrderId]
	currAttempts := len(order.PaymentAttempts)
	if currAttempts < p.MaxAttempts {
		newPayment := p.PaymentService.createPayment(order.Amount, order.Currency, order.OrderId)
		order.PaymentAttempts = append(order.PaymentAttempts, newPayment)
		p.PaymentGatewayOrchestrator.Route(newPayment.OrderId, newPayment.Amount, newPayment.Currency, newPayment.PaymentId)
	}
}
