package main

type NotificationFactory struct {
	NotificationChannels map[NOTIFICATION_CHANNEL]NotificationChannel
}

func NewNotificationFactory(NotificationChannels map[NOTIFICATION_CHANNEL]NotificationChannel) *NotificationFactory {
	return &NotificationFactory{
		NotificationChannels,
	}
}

func (n *NotificationFactory) GetNotificationChannel(Channel NOTIFICATION_CHANNEL) NotificationChannel {
	channel, ok := n.NotificationChannels[Channel]
	if ok {
		return channel
	}
	return nil
}
