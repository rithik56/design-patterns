package main

type OrderMetadata struct {
	OrderId  string
	Amount   int
	Currency string
}

func NewOrderMetadata(OrderId string, Amount int, Currency string) *OrderMetadata {
	return &OrderMetadata{
		OrderId,
		Amount,
		Currency,
	}
}
