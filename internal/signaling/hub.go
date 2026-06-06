package signaling

import (
	"fmt"

	"mudscript/driver"
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
			h.clients[client.ID] = client

			if !client.IsP2P {
				pConn := driver.NewPlayerConnection(nil, nil) 
				pConn.SessionID = client.ID
				pConn.Username = client.Username
				
				pConn.OutputCallback = func(mudText string) {
					defer func() { recover() }() // 🚀 安全防護
					if pConn.IsActive {
						select {
						case client.Send <- Message{
							Type:    "mud_text",
							Payload: mudText,
						}:
						default:
						}
					}
				}

				userObj := h.mudDriver.AcceptConnection(pConn, client.Language)
				if userObj != nil {
					pConn.Object = userObj
					h.mudDriver.RegisterInteractive(userObj, pConn)
					h.mudDriver.RunCommand(pConn, userObj, "logon", nil)
					client.MudConn = pConn 
				} else {
					fmt.Println("⚠️ 系統拒絕了", client.Username, "的連線")
				}
			}

			client.Send <- Message{
				Type: "welcome",
				To:   client.ID,
				Username: client.Username,
			}

			for id, peer := range h.clients {
				if id != client.ID {
					peer.Send <- Message{
						Type: "peer-joined",
						From: client.ID,
						To:   id,
						Username: client.Username,
					}
					client.Send <- Message{
						Type: "peer-joined",
						From: id,
						To:   client.ID,
						Username: peer.Username,
					}
				}
			}

			if client.IsP2P {
				h.BroadcastChat("SYSTEM", "一個新的 MUD 伺服器節點已加入星際網路。")
			}

		case client := <-h.unregister:
			if _, ok := h.clients[client.ID]; ok {
				delete(h.clients, client.ID)
				
				if client.MudConn != nil {
					client.MudConn.IsActive = false
					if client.MudConn.Object != nil {
						h.mudDriver.RunCommand(client.MudConn, client.MudConn.Object, "net_dead", nil)
						h.mudDriver.UnregisterInteractive(client.MudConn.Object)
					}
					client.MudConn.OutputCallback = nil
				}
				
				close(client.Send)
			}

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
				
				// 🚀 關鍵修正：統一調用 Driver 的核心指令處理邏輯
				// 這會確保 Web 客戶端與 Telnet 客戶端的行為完全一致
				h.mudDriver.ProcessCommand(p, msg.Payload)

			} else if msg.Type == "chat" {
				if h.mudDriver != nil && h.mudDriver.OnP2PMessage != nil {
					h.mudDriver.OnP2PMessage(msg.Username, msg.Payload)
				}

				for id, peer := range h.clients {
					if peer.IsP2P {
						select {
						case peer.Send <- msg:
						default:
						}
					} else if id != msg.From {
						select {
						case peer.Send <- msg:
						default:
						}
					}
				}
			} else {
				if peer, ok := h.clients[msg.To]; ok {
					select {
					case peer.Send <- msg:
					default:
					}
				}
			}
		}
	}
}

func (h *Hub) UpdateClientUsername(id, newName string) {
	if client, ok := h.clients[id]; ok {
		client.Username = newName
	}
}

func (h *Hub) BroadcastChat(sender, content string) {
	h.forward <- Message{
		Type:     "chat",
		From:     "local",
		Username: sender,
		Payload:  content,
	}
}
