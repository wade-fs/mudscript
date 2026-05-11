package signaling

import (
)

type Hub struct {
	clients    map[string]*Client
	register   chan *Client
	unregister chan *Client
	forward    chan Message
}

func NewHub() *Hub {
	return &Hub{
		clients:    map[string]*Client{},
		register:   make(chan *Client),
		unregister: make(chan *Client),
		forward:    make(chan Message, 1024),
	}
}

func (h *Hub) Run() {
	for {
		select {
		case client := <-h.register:
			// 1. 將新客戶端加入列表
			h.clients[client.ID] = client

			// 2. 告訴新客戶端他自己的 ID (歡迎訊息)
			client.Send <- Message{
				Type: "welcome",
				To:   client.ID,
				Username: client.Username,
			}

			// 3. 雙向廣播：讓新舊客戶端互相認識
			for id, peer := range h.clients {
				if id != client.ID {
					// 告訴舊成員：有新人加入
					peer.Send <- Message{
						Type: "peer-joined",
						From: client.ID,
						To:   id,
						Username: client.Username,
					}
					// 告訴新人：目前在線上的舊成員有哪些
					client.Send <- Message{
						Type: "peer-joined",
						From: id,
						To:   client.ID,
						Username: peer.Username,
					}
				}
			}

		case client := <-h.unregister:
			// 1. 從列表中移除
			if _, ok := h.clients[client.ID]; ok {
				delete(h.clients, client.ID)
				close(client.Send) // 關閉 channel，讓 writeLoop 安全退出
			}

			// 2. 廣播給剩下的所有人：有人離開了
			for id, peer := range h.clients {
				peer.Send <- Message{
					Type: "peer-left",
					From: client.ID,
					To:   id,
					Username: client.Username,
				}
			}

		case msg := <-h.forward:
			
			// 新增：如果是聊天訊息，廣播給所有其他人
			if msg.Type == "chat" {
				for id, peer := range h.clients {
					// 不要把訊息發回給自己 (msg.From 在 client.go 的 readLoop 已經自動被填上了)
					if id != msg.From {
						peer.Send <- msg
					}
				}
			} else {
				// 原本的邏輯：點對點的 WebRTC Signaling (Offer/Answer/Candidate)
				if peer, ok := h.clients[msg.To]; ok {
					peer.Send <- msg
				}
			}
		}
	}
}
