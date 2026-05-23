package signaling

import (
	"encoding/json"
	"net/http"
	"strings"

	"github.com/google/uuid"
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
	Conn     *websocket.Conn
	Hub      *Hub
	Send     chan Message
	MudConn  *driver.PlayerConnection
}

func HandleWS(hub *Hub, w http.ResponseWriter, r *http.Request) {
	conn, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		return
	}

	// 1. 從 URL 查詢參數中獲取 username
	username := r.URL.Query().Get("username")
	if username == "" {
		username = "Anonymous" // 如果沒填，給個預設值
	}

	// 🚀 新增：獲取瀏覽器語言 (Accept-Language)
	lang := r.Header.Get("Accept-Language")
	if lang != "" {
		// 簡化處理：取第一個主要語言標籤，例如 "zh-TW,zh;q=0.9" -> "zh-TW"
		if pos := strings.Index(lang, ","); pos != -1 {
			lang = lang[:pos]
		}
	}

	client := &Client{
		ID:       uuid.NewString(),
		Username: username,
		Language: lang, // 存入 Client
		Conn:     conn,
		Hub:      hub,
		Send:     make(chan Message, 256),
	}

	hub.register <- client

	go client.writeLoop()
	go client.readLoop()
}

func (c *Client) readLoop() {
	defer func() {
		c.Hub.unregister <- c
		c.Conn.Close()
	}()

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

		// 3. 伺服器強制覆蓋 From 與 Username，防止前端偽造身分
		msg.From = c.ID
		msg.Username = c.Username

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
