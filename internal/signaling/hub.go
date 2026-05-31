package signaling

import (
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
					client.Send <- Message{
						Type:    "mud_text",
						Payload: mudText,
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
				close(client.Send)
			}

			if client.MudConn != nil && client.MudConn.Object != nil {
				h.mudDriver.RunCommand(client.MudConn, client.MudConn.Object, "net_dead", nil)
				h.mudDriver.UnregisterInteractive(client.MudConn.Object)
				client.MudConn.IsActive = false
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
				input := strings.TrimSpace(msg.Payload)
				if input == "" {
					continue
				}

				if p.NextInputFunc != "" {
					funcName := p.NextInputFunc
					p.NextInputFunc = ""
					p.InputHidden = false
					h.mudDriver.RunCommand(p, p.Object, funcName, []object.Object{&object.String{Value: input}})
					continue
				}

				expanded := h.mudDriver.RunCommand(p, p.Object, "expand_alias", []object.Object{&object.String{Value: input}})
				if s, ok := expanded.(*object.String); ok {
					input = s.Value
				}

				input = strings.TrimSpace(input)
				verb := ""
				arg := ""

				if strings.HasPrefix(input, "'") {
					verb = "'"
					arg = strings.TrimSpace(input[1:])
				} else if strings.HasPrefix(input, ":") {
					verb = ":"
					arg = strings.TrimSpace(input[1:])
				} else {
					parts := strings.SplitN(input, " ", 2)
					verb = parts[0]
					if len(parts) > 1 {
						arg = parts[1]
					}
				}

				p.CurrentVerb = verb

				found := false
				if p.Object.Actions != nil {
					if action, exists := p.Object.Actions[verb]; exists {
						res := h.mudDriver.RunCommand(p, action.Provider, action.FuncName, []object.Object{&object.String{Value: arg}})
						if i, ok := res.(*object.Integer); ok && i.Value != 0 {
							found = true
						}
					}
				}

				if (!found) {
					h.mudDriver.RunCommand(p, p.Object, "process_input", []object.Object{&object.String{Value: input}})
				}
			} else if msg.Type == "chat" {
				// 🚀 階段 1：將訊息轉發給本地 MUD 驅動 (給 Hub 本身的玩家看)
				if h.mudDriver != nil && h.mudDriver.OnP2PMessage != nil {
					h.mudDriver.OnP2PMessage(msg.Username, msg.Payload)
				}

				// 🚀 階段 2：轉發給其他連線中的節點
				for id, peer := range h.clients {
					// 路由策略：
					// 1. 如果目標是 P2P 節點：一律轉發 (包含發送者，作為回信確認)
					// 2. 如果目標是 Web 玩家：只有在對方「不是」發送者時才轉發
					if peer.IsP2P {
						// P2P 節點：非阻塞發送
						select {
						case peer.Send <- msg:
						default:
						}
					} else if id != msg.From {
						// Web 玩家：非阻塞發送
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
