package signaling

import (
	"encoding/json"
	"fmt"
	"strings"

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
		clients:    make(map[string]*Client),
		register:   make(chan *Client),
		unregister: make(chan *Client),
		forward:    make(chan Message),
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
						msgType := "mud_text"
						payload := mudText
						if strings.HasPrefix(mudText, "__RAW__") {
							msgType = "mud_html"
							payload = strings.TrimPrefix(mudText, "__RAW__")
						} else if strings.HasPrefix(mudText, "__EDIT__") {
							msgType = "edit_file"
							payload = strings.TrimPrefix(mudText, "__EDIT__")
						}
						select {
						case client.Send <- Message{
							Type:    msgType,
							Payload: payload,
						}:
						default:
						}
					}
				}

				userObj := h.mudDriver.AcceptConnection(pConn, client.Language)
				if userObj != nil {
					pConn.Object = userObj
					if pConn.Object != nil {
						pConn.Object.Vars.Set("is_web", &object.Integer{Value: 1})
					}
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
					if client.MudConn.Object != nil {
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
				h.mudDriver.ProcessCommand(p, msg.Payload)

			} else if msg.Type == "save_file" {
				client, ok := h.clients[msg.From]
				if !ok || client.MudConn == nil { continue }
				
				var data struct {
					Path    string `json:"path"`
					Content string `json:"content"`
				}
				if err := json.Unmarshal([]byte(msg.Payload), &data); err == nil {
					if err := h.mudDriver.WriteFile(data.Path, []byte(data.Content)); err == nil {
						h.mudDriver.TellObject(client.MudConn.Object, "✅ 檔案 " + data.Path + " 已儲存。\n")
						h.mudDriver.ProcessCommand(client.MudConn, "update " + data.Path)
					} else {
						h.mudDriver.TellObject(client.MudConn.Object, "❌ 儲存失敗：" + err.Error() + "\n")
					}
				}
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
				if msg.To != "" {
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
}

func (h *Hub) UpdateClientUsername(id, newName string) {
	if client, ok := h.clients[id]; ok {
		client.Username = newName
	}
}

func (h *Hub) BroadcastChat(username, payload string) {
	msg := Message{
		Type:     "chat",
		Username: username,
		Payload:  payload,
	}
	h.forward <- msg
}
