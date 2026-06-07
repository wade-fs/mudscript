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
	cmd := exec.Command("./bin/fsmud", "-mudlib", "fsmud", "-master", "master.c", "-hub", "none", "-port", "8090")
	if err := cmd.Start(); err != nil { log.Fatalf("Err: %v", err) }
	defer cmd.Process.Kill()
	time.Sleep(3 * time.Second)

	u := url.URL{Scheme: "ws", Host: "localhost:8090", Path: "/ws"}
	conn, _, err := websocket.DefaultDialer.Dial(u.String(), nil)
	if err != nil { log.Fatalf("WS: %v", err) }
	defer conn.Close()

	received := make(chan string, 100)
	go func() {
		for {
			_, message, err := conn.ReadMessage()
			if err != nil { return }
			var msg WsMsg
			if err := json.Unmarshal(message, &msg); err == nil {
				if msg.Type != "" {
					fmt.Printf("🖥️  [%s]: %s\n", msg.Type, msg.Payload)
					received <- msg.Type
				}
			}
		}
	}()

	send := func(text string) {
		fmt.Printf("⌨️  [Client]: %s\n", text)
		p, _ := json.Marshal(WsMsg{Type: "cmd", Payload: text})
		conn.WriteMessage(websocket.TextMessage, p)
		time.Sleep(1 * time.Second)
	}

	send("2")      // Traditional Chinese
	send("wade")   // ID
	send("jj")     // Pass
	time.Sleep(3 * time.Second) // Wait for login to finish
	send("edit /master.c")
	
	deadline := time.Now().Add(10 * time.Second)
	for time.Now().Before(deadline) {
		select {
		case t := <-received:
			if t == "edit_file" {
				fmt.Println("🎉 SUCCESS: Web IDE edit_file received!")
				return
			}
		default:
			time.Sleep(100 * time.Millisecond)
		}
	}
	fmt.Println("❌ FAILURE: No edit_file message.")
}
