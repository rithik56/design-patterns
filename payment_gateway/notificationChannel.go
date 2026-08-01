package main

type NotificationChannel interface {
	SendNotification(notification *Notification)
}
