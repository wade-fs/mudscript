package signaling

import (
	"encoding/json"
	"net/http"
	"sync"

	"github.com/gorilla/websocket"
	"mudscript/driver"
)

var upgrader = websocket.Upgrader{
	CheckOrigin: func(r *http.Request) bool {
		return true
	},
}

type Client struct {
	ID       string
	Username string
	Language string // 🚀 新增：瀏覽器語言
	IsP2P    bool   // 🚀 新增：標記是否為 P2P 節點
	Conn     *websocket.Conn
	Hub      *Hub
	Send     chan Message
	MudConn  *driver.PlayerConnection
	
	mu       sync.Mutex
	closed   bool
}

func HandleWS(hub *Hub, w http.ResponseWriter, r *http.Request) {
// ... (keep HandleWS same, but remember to initialize mu if needed, but it's default)
}

func (c *Client) SafeSend(msg Message) {
	c.mu.Lock()
	defer c.mu.Unlock()
	if c.closed {
		return
	}
	select {
	case c.Send <- msg:
	default:
		// 如果 Buffer 滿了，則捨棄訊息以避免阻塞 Hub 核心迴圈
	}
}

func (c *Client) Close() {
	c.mu.Lock()
	if c.closed {
		c.mu.Unlock()
		return
	}
	c.closed = true
	close(c.Send)
	c.mu.Unlock()
	
	if c.Conn != nil {
		c.Conn.Close()
	}
}

func (c *Client) readLoop() {
	defer func() {
		c.Hub.unregister <- c
		c.Close()
	}()
// ...

	for {
		_, data, err := c.Conn.ReadMessage()
		if err != nil {
			return
		}

		var msg Message
		err = json.Unmarshal(data, &msg)
		if err != nil {
			continue
		}

		// 3. 伺服器安全性處理
		msg.From = c.ID
		// 🚀 關鍵修正：如果是 P2P 節點，我們信任它傳來的 Username (角色暱稱)
		// 如果是普通 Web 客戶端，則維持強制覆蓋，防止偽造身分
		if !c.IsP2P {
			msg.Username = c.Username
		}

		c.Hub.forward <- msg
	}
}

func (c *Client) writeLoop() {

	for msg := range c.Send {

		err := c.Conn.WriteJSON(msg)
		if err != nil {
			return
		}
	}
}
