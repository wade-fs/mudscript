package signaling

import (
	"fmt"

	"mudscript/driver"
	"mudscript/object"
)

type Hub struct {
	clients    map[string]*Client
	register   chan *Client
	unregister chan *Client
	forward    chan Message

	mudDriver  *driver.Driver
}

func NewHub(d *driver.Driver) *Hub {
	return &Hub{
		clients:    map[string]*Client{},
		register:   make(chan *Client),
		unregister: make(chan *Client),
		forward:    make(chan Message, 1024),
		mudDriver:  d,
	}
}

func (h *Hub) Run() {
	for {
		select {
		case client := <-h.register:
			// 1. 將新客戶端加入列表
			h.clients[client.ID] = client

			// ==========================================
			// 🚀 MUD 整合：玩家登入流程
			// ==========================================
			
			// A. 建立一個專屬於此 WebSocket 的 PlayerConnection
			// 這裡的 conn 傳 nil，因為我們不用傳統 TCP
			pConn := driver.NewPlayerConnection(nil, nil) 
			pConn.Username = client.Username
			
			pConn.OutputCallback = func(mudText string) {
			    // 確保 client 還在線上
			    client.Send <- Message{
			        Type:    "mud_text",
			        Payload: mudText,
			    }
			}

            // C. 向 Master Object 請求登入物件 (這會執行 master.c 的 connect())
			userObj := h.mudDriver.AcceptConnection(pConn)
			if userObj != nil {
				pConn.Object = userObj
				// 註冊互動狀態
				h.mudDriver.RegisterInteractive(userObj, pConn)
				// 觸發 Logon 函數
				h.mudDriver.RunCommand(pConn, userObj, "logon", nil)
				
				// 為了方便後續查詢，把這個 pConn 存進 WebSocket Client 裡
				// (您需要在 signaling.Client 結構中新增一個 MudConn *driver.PlayerConnection 欄位)
				client.MudConn = pConn 
			} else {
				fmt.Println("⚠️ 系統拒絕了", client.Username, "的連線")
				// 可以在這裡發送錯誤訊息給 Client 並關閉連線
			}

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

			// ==========================================
			// 🚀 MUD 整合：玩家斷線流程
			// ==========================================
			if client.MudConn != nil && client.MudConn.Object != nil {
				// 觸發 user.c 中的斷線處理邏輯 (通常是 net_dead 或 quit)
				h.mudDriver.RunCommand(client.MudConn, client.MudConn.Object, "net_dead", nil)
				
				// 解除註冊
				h.mudDriver.UnregisterInteractive(client.MudConn.Object)
				client.MudConn.IsActive = false
			}
			// ==========================================

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
		    if msg.Type == "cmd" {
				client, ok := h.clients[msg.From]
				if !ok || client.MudConn == nil {
					continue
				}

				p := client.MudConn
				// 👉 關鍵修正：優先檢查是否有等待中的 input_to 函式
				if p.NextInputFunc != "" {
					funcName := p.NextInputFunc
					p.NextInputFunc = "" // 執行一次後立即清除狀態
					p.InputHidden = false // 重設隱藏狀態

					// 將輸入直接送往該函式
					h.mudDriver.RunCommand(p, p.Object, funcName, []object.Object{
						&object.String{Value: msg.Payload},
					})
				} else {
					// 正常的指令處理流程 (例如 look, move 等)
					// 您可以考慮在這裡加入 add_action 的檢查邏輯，或是交給 process_input
					h.mudDriver.RunCommand(p, p.Object, "process_input", []object.Object{
						&object.String{Value: msg.Payload},
					})
				}
			} else if msg.Type == "chat" {
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
