package main

import (
	"github.com/google/uuid"
)

type NOTIFICATION_STATUS string

const (
	NotificationStatusPending NOTIFICATION_STATUS = "PENDING"
	NotificationStatusSuccess NOTIFICATION_STATUS = "SUCCESS"
	NotificationStatusFailed  NOTIFICATION_STATUS = "FAILED"
)

type NOTIFICATION_CHANNEL string

const (
	NotificationChannelEmail NOTIFICATION_CHANNEL = "EMAIL"
	NotificationChannelSms   NOTIFICATION_CHANNEL = "SMS"
)

type Notification struct {
	NotificationId string
	OrderId        string
	Msg            string
	Status         NOTIFICATION_STATUS
	Channel        NOTIFICATION_CHANNEL
	CreatedAt      string
	UpdatedAt      string
}

func NewNotification(Msg string, OrderId string, Channel NOTIFICATION_CHANNEL) *Notification {
	return &Notification{
		NotificationId: uuid.New().String(),
		OrderId:        OrderId,
		Msg:            Msg,
		Channel:        Channel,
		Status:         NotificationStatusPending,
		CreatedAt:      "30/07/2026",
		UpdatedAt:      "30/07/2026",
	}
}
