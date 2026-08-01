package main

type OrderService struct {
	Orders         map[string]*Order
	PaymentService *PaymentService
}

func NewOrderService(PaymentService *PaymentService) *OrderService {
	return &OrderService{
		Orders:         make(map[string]*Order),
		PaymentService: PaymentService,
	}
}

func (o *OrderService) createOrder(Amount int, Currency string, Products map[string]int) *Order {
	newOrder := NewOrder(Amount, Currency, Products)
	o.Orders[newOrder.OrderId] = newOrder
	payment := o.PaymentService.createPayment(Amount, Currency, newOrder.OrderId)
	newOrder.PaymentAttempts = append(newOrder.PaymentAttempts, payment)
	return newOrder
}
