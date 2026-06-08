package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/url"
	"os/exec"
	"time"

	"github.com/gorilla/websocket"
)

type WsMsg struct {
	Type    string `json:"type"`
	Payload string `json:"payload"`
}

func main() {
	cmd := exec.Command("./bin/fs", "-mudlib", "fs", "-master", "/adm/obj/master.c", "-legacy", "-port", "8091")
	if err := cmd.Start(); err != nil { log.Fatalf("Err: %v", err) }
	defer cmd.Process.Kill()
	time.Sleep(3 * time.Second)

	u := url.URL{Scheme: "ws", Host: "localhost:8091", Path: "/ws"}
	conn, _, err := websocket.DefaultDialer.Dial(u.String(), nil)
	if err != nil { log.Fatalf("WS: %v", err) }
	defer conn.Close()

	go func() {
		for {
			_, message, _ := conn.ReadMessage()
			var msg WsMsg
			if err := json.Unmarshal(message, &msg); err == nil {
				fmt.Printf("🖥️  [%s]: %s\n", msg.Type, msg.Payload)
			}
		}
	}()

	send := func(text string) {
		fmt.Printf("⌨️  [Client]: %s\n", text)
		p, _ := json.Marshal(WsMsg{Type: "cmd", Payload: text})
		conn.WriteMessage(websocket.TextMessage, p)
		time.Sleep(1 * time.Second)
	}

	send("guest")
	send("")
	time.Sleep(1 * time.Second)
	send("look")
	time.Sleep(3 * time.Second)
}
