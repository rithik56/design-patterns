package main

type StatusCounter struct {
	SuccessCount int
	FailureCount int
	PendingCount int
}

func NewStatusCounter() *StatusCounter {
	return &StatusCounter{
		SuccessCount: 0,
		FailureCount: 0,
		PendingCount: 0,
	}
}
