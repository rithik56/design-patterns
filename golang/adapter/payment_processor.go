package main

type PaymentProcessor interface {
	pay(amount int)
}
