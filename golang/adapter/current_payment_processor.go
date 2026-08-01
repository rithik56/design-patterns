package main

import "fmt"

type CurrentPaymentProcessor struct{}

func (currentPaymentProcessor *CurrentPaymentProcessor) pay(amount int) {
	fmt.Println("payment done by current payment processor system")
}
