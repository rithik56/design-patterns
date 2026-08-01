package main

type ReconcillationJob struct {
	PaymentStatusUpdateService    *PaymentStatusUpdateService
	PaymentServiceProviderFactory *PaymentServiceProviderFactory
	PaymentService                *PaymentService
}

func NewReconcillationJob(PaymentStatusUpdateService *PaymentStatusUpdateService, PaymentServiceProviderFactory *PaymentServiceProviderFactory, PaymentService *PaymentService) *ReconcillationJob {
	return &ReconcillationJob{
		PaymentStatusUpdateService,
		PaymentServiceProviderFactory,
		PaymentService,
	}
}

func (r *ReconcillationJob) runReconcillation() {
	for _, payment := range r.PaymentService.Payments {
		if payment.Status == PaymentStatusPending {
			checkStatus := r.PaymentServiceProviderFactory.GetPaymentServiceProviderById(payment.PaymentServiceProviderId).CheckPaymentStatus(payment.CheckoutResponseId)
			if checkStatus != PaymentStatusPending {
				r.PaymentStatusUpdateService.updateStatus(payment.PaymentId, checkStatus)
			}
		}
	}
}
