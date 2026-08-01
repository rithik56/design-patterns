package main

import (
	"github.com/google/uuid"
)

type PAYMENT_STATUS string

const (
	PaymentStatusPending PAYMENT_STATUS = "PENDING"
	PaymentStatusSuccess PAYMENT_STATUS = "SUCCESS"
	PaymentStatusFailed  PAYMENT_STATUS = "FAILED"
)

type Payment struct {
	PaymentId                string
	Amount                   int
	Currency                 string
	Status                   PAYMENT_STATUS
	CheckoutResponseId       string
	OrderId                  string
	CreatedAt                string
	UpdatedAt                string
	PaymentServiceProviderId string
}

func NewPayment(Amount int, Currency string, OrderId string) *Payment {
	return &Payment{
		PaymentId: uuid.New().String(),
		Amount:    Amount,
		Currency:  Currency,
		Status:    PaymentStatusPending,
		OrderId:   OrderId,
		CreatedAt: "30/07/2026",
		UpdatedAt: "30/07/2026",
	}
}
