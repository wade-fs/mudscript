// cmd/test-fsmud/main.go
package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"log"
	"net/url"
	"os"
	"strings"
	"time"

	"github.com/gorilla/websocket"
)

type WsMsg struct {
	Type    string `json:"type"`
	Payload string `json:"payload"`
}

var colorMap = map[string]string{
	"$BLK$": "\x1b[0;30m",
	"$RED$": "\x1b[0;31m",
	"$GRN$": "\x1b[0;32m",
	"$YEL$": "\x1b[0;33m",
	"$BLU$": "\x1b[0;34m",
	"$MAG$": "\x1b[0;35m",
	"$CYN$": "\x1b[0;36m",
	"$WHT$": "\x1b[0;37m",
	"$HIK$": "\x1b[1;30m",
	"$HIR$": "\x1b[1;31m",
	"$HIG$": "\x1b[1;32m",
	"$HIY$": "\x1b[1;33m",
	"$HIB$": "\x1b[1;34m",
	"$HIM$": "\x1b[1;35m",
	"$HIC$": "\x1b[1;36m",
	"$HIW$": "\x1b[1;37m",
	"$NOR$": "\x1b[0m",
}

func toAnsi(text string) string {
	for k, v := range colorMap {
		text = strings.ReplaceAll(text, k, v)
	}
	return text
}

func main() {
	log.Println("🔌 正在連線至 fsmud 伺服器 (ws://localhost:8080/ws)...")
	u := url.URL{Scheme: "ws", Host: "localhost:8080", Path: "/ws"}
	conn, _, err := websocket.DefaultDialer.Dial(u.String(), nil)
	if err != nil {
		log.Fatalf("❌ 連線失敗: %v\n請確認伺服器已透過 'make run-fsmud' 啟動，且監聽在 8080 埠。", err)
	}
	defer conn.Close()
	log.Println("✅ 連線成功！")

	received := make(chan string, 100)
	go func() {
		for {
			_, message, err := conn.ReadMessage()
			if err != nil {
				log.Println("\n❌ 與伺服器連線中斷。")
				os.Exit(0)
				return
			}
			var msg WsMsg
			if err := json.Unmarshal(message, &msg); err == nil {
				if msg.Type == "mud_text" || msg.Type == "chat" {
					fmt.Print(toAnsi(msg.Payload))
					received <- msg.Payload
				}
			}
		}
	}()

	sendMsg := func(text string) {
		payload, _ := json.Marshal(WsMsg{Type: "cmd", Payload: text})
		conn.WriteMessage(websocket.TextMessage, payload)
	}

	// 模擬自動登入程序與互動
	time.Sleep(500 * time.Millisecond)
	
	log.Println("\n🤖 [自動測試] 選擇語系：2 (繁體中文)")
	sendMsg("2")
	time.Sleep(800 * time.Millisecond)

	log.Println("🤖 [自動測試] 輸入帳號：wade")
	sendMsg("wade")
	time.Sleep(800 * time.Millisecond)

	log.Println("🤖 [自動測試] 輸入密碼：jj")
	sendMsg("jj")
	time.Sleep(1500 * time.Millisecond)

	// 執行測試指令清單
	testCmds := []string{
		"ls",
		"pwd",
		"look",
		"out",
		"lm",
		"look",
	}

	for _, cmd := range testCmds {
		log.Printf("\n🤖 [自動測試] 執行指令：%s", cmd)
		sendMsg(cmd)
		time.Sleep(1500 * time.Millisecond) // 等待伺服器回應與看清輸出
	}

	log.Println("\n🎉 [自動測試] 自動腳本執行完畢！已切換至互動模式。")
	log.Println("👉 您現在可以直接在下方輸入指令與 MUD 互動（例如輸入 'east'、'look'、'help' 等，輸入 'quit' 可結束）：")

	// 啟動互動式讀取
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		input := scanner.Text()
		if input == "quit" || input == "exit" {
			log.Println("👋 正在離開測試程式...")
			break
		}
		sendMsg(input)
	}
}
