package main

import (
	"fmt"
)

type SmsNotification struct {
}

func NewSmsNotification() *SmsNotification {
	return &SmsNotification{}
}

func (e *SmsNotification) SendNotification(Notification *Notification) {
	fmt.Println("sms notification sent")
	Notification.Status = NotificationStatusSuccess
}
