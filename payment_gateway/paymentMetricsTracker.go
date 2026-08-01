package main

type PaymentMetricsTracker struct {
	Metrics map[string]*StatusCounter
}

func NewPaymentMetricsTracker() *PaymentMetricsTracker {
	return &PaymentMetricsTracker{
		Metrics: make(map[string]*StatusCounter),
	}
}

func (p *PaymentMetricsTracker) RecordResult(PaymentServiceProviderId string, PaymentStatus PAYMENT_STATUS) {
	statusCounter, ok := p.Metrics[PaymentServiceProviderId]
	if ok {
		switch PaymentStatus {
		case PaymentStatusPending:
			statusCounter.PendingCount++
		case PaymentStatusFailed:
			statusCounter.FailureCount++
		default:
			statusCounter.SuccessCount++
		}
	}
}

func (p *PaymentMetricsTracker) GetSuccessRate(PaymentServiceProviderId string) float64 {
	statusCounter, ok := p.Metrics[PaymentServiceProviderId]
	if ok {
		resolved := statusCounter.SuccessCount + statusCounter.FailureCount
		if resolved == 0 {
			return 0
		}
		return float64(statusCounter.SuccessCount) / float64(resolved)
	}
	return 0
}
