package main

import (
	"github.com/google/uuid"
)

type ORDER_STATUS string

const (
	OrderStatusCreated           ORDER_STATUS = "CREATED"
	OrderStatusPaymentPending    ORDER_STATUS = "PAYMENT_PENDING"
	OrderStatusPaymentSuccessful ORDER_STATUS = "PAYMENT_SUCCESS"
	OrderStatusPaymentFailed     ORDER_STATUS = "PAYMENT_FAILED"
)

type Order struct {
	OrderId         string
	Amount          int
	Currency        string
	Status          ORDER_STATUS
	PaymentAttempts []*Payment
	CreatedAt       string
	UpdatedAt       string
	Products        map[string]int
}

func NewOrder(Amount int, Currency string, Products map[string]int) *Order {
	return &Order{
		OrderId:         uuid.New().String(),
		Amount:          Amount,
		Currency:        Currency,
		Status:          OrderStatusCreated,
		Products:        Products,
		PaymentAttempts: make([]*Payment, 0),
		CreatedAt:       "30/07/2026",
		UpdatedAt:       "30/07/2026",
	}
}
