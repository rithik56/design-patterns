package main

type RawWebhookRequest struct {
	Body        []byte
	Headers     map[string]string
	ContentType string
}

func NewRawWebhookRequest(Body []byte, Headers map[string]string, ContentType string) *RawWebhookRequest {
	return &RawWebhookRequest{
		Body,
		Headers,
		ContentType,
	}
}
