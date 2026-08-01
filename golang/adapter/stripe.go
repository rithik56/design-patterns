package main

import "fmt"

type Stripe struct{}

func (s Stripe) charge(amount int) {
	fmt.Println("payment done by stripe")
}
