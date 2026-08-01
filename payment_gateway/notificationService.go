package main

type NotificationService struct {
	Notifications       map[string]*Notification
	NotificationFactory *NotificationFactory
}

func NewNotificationService(NotificationFactory *NotificationFactory) *NotificationService {
	return &NotificationService{
		Notifications:       make(map[string]*Notification),
		NotificationFactory: NotificationFactory,
	}
}

func (n *NotificationService) NotifyUser(Msg string, OrderId string, Channel NOTIFICATION_CHANNEL) {
	notificationChannel := n.NotificationFactory.GetNotificationChannel(Channel)
	if notificationChannel != nil {
		newNotification := NewNotification(Msg, OrderId, Channel)
		n.Notifications[newNotification.NotificationId] = newNotification
		notificationChannel.SendNotification(newNotification)
	}
}
