package main

import (
	"fmt"
)

type EmailNotification struct {
}

func NewEmailNotification() *EmailNotification {
	return &EmailNotification{}
}

func (e *EmailNotification) SendNotification(Notification *Notification) {
	fmt.Println("email notification sent")
	Notification.Status = NotificationStatusSuccess
}
