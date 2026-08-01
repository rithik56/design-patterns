package main

type PaymentStatusUpdateService struct {
	PaymentService        *PaymentService
	OrderService          *OrderService
	PaymentRetryService   *PaymentRetryService
	NotificationService   *NotificationService
	PaymentMetricsTracker *PaymentMetricsTracker
}

func NewPaymentStatusUpdateService(PaymentService *PaymentService, OrderService *OrderService, PaymentRetryService *PaymentRetryService, NotificationService *NotificationService, PaymentMetricsTracker *PaymentMetricsTracker) *PaymentStatusUpdateService {
	return &PaymentStatusUpdateService{
		PaymentService,
		OrderService,
		PaymentRetryService,
		NotificationService,
		PaymentMetricsTracker,
	}
}

func (p *PaymentStatusUpdateService) updateStatus(PaymentId string, PaymentStatus PAYMENT_STATUS) {
	Payment := p.PaymentService.Payments[PaymentId]
	if PaymentStatus == Payment.Status {
		return
	}
	Payment.Status = PaymentStatus
	if PaymentStatus == PaymentStatusFailed {
		p.PaymentMetricsTracker.RecordResult(Payment.PaymentServiceProviderId, PaymentStatusFailed)
		p.OrderService.Orders[Payment.OrderId].Status = OrderStatusPaymentFailed
		p.PaymentRetryService.retryPayment(Payment)
	} else if PaymentStatus == PaymentStatusSuccess {
		p.PaymentMetricsTracker.RecordResult(Payment.PaymentServiceProviderId, PaymentStatusSuccess)
		p.OrderService.Orders[Payment.OrderId].Status = OrderStatusPaymentSuccessful
		p.NotificationService.NotifyUser("payment done successfully", Payment.OrderId, NotificationChannelEmail)
	}
}
