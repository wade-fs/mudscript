// cmd/test-fs/main.go
package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"log"
	"net/url"
	"os"
	"os/exec"
	"strings"
	"time"

	"github.com/gorilla/websocket"
)

type WsMsg struct {
	Type    string `json:"type"`
	Payload string `json:"payload"`
}

func main() {
	// 1. 啟動 bin/fs 伺服器 (Legacy FS 模式)
	log.Println("🚀 正在啟動 Legacy FS 伺服器進行整合測試...")

	// 使用內嵌了 fs 資源的專屬 binary
	cmd := exec.Command("./bin/fs", "-mudlib", "fs", "-master", "/adm/obj/master.c", "-legacy")

	// 為了能觀察內部錯誤，我們捕獲輸出
	stdout, _ := cmd.StdoutPipe()
	cmd.Stderr = os.Stderr

	if err := cmd.Start(); err != nil {
		log.Fatalf("無法啟動伺服器: %v", err)
	}

	// 非同步讀取伺服器日誌
	go func() {
		scanner := bufio.NewScanner(stdout)
		for scanner.Scan() {
			line := scanner.Text()
			if strings.Contains(line, "RUNTIME ERROR") || strings.Contains(line, "panic") {
				fmt.Printf("\n🔥 [SERVER ERROR]: %s\n", line)
			}
		}
	}()

	defer func() {
		log.Println("🛑 正在關閉伺服器...")
		cmd.Process.Kill()
	}()

	// 2. 等待伺服器就緒
	time.Sleep(3 * time.Second)

	// 3. 建立 WebSocket 連線
	log.Println("🔌 正在建立 WebSocket 連線至 localhost:8080...")
	u := url.URL{Scheme: "ws", Host: "localhost:8080", Path: "/ws"}
	conn, _, err := websocket.DefaultDialer.Dial(u.String(), nil)
	if err != nil {
		log.Fatalf("連線失敗: %v", err)
	}
	defer conn.Close()

	// 讀取回傳並匹配關鍵字
	received := make(chan string, 100)
	go func() {
		for {
			_, message, err := conn.ReadMessage()
			if err != nil {
				return
			}
			var msg WsMsg
			if err := json.Unmarshal(message, &msg); err == nil {
				if msg.Type == "mud_text" || msg.Type == "chat" {
					fmt.Printf("🖥️  [Server]: %s\n", msg.Payload)
					received <- msg.Payload
				}
			}
		}
	}()

	// 輔助函式：等待特定字串出現
	waitFor := func(keyword string, timeout time.Duration) bool {
		deadline := time.Now().Add(timeout)
		for time.Now().Before(deadline) {
			select {
			case msg := <-received:
				if strings.Contains(msg, keyword) {
					return true
				}
			case <-time.After(100 * time.Millisecond):
				continue
			}
		}
		return false
	}

	// 4. 模擬登入流程

	// A. 輸入 guest
	log.Println("⌨️  [Client]: 正在輸入 'guest'...")
	sendMsg := func(text string) {
		payload, _ := json.Marshal(WsMsg{Type: "cmd", Payload: text})
		conn.WriteMessage(websocket.TextMessage, payload)
	}

	sendMsg("guest")

	if !waitFor("請按 Enter 鍵繼續", 5*time.Second) {
		log.Println("⚠️  未偵測到 '請按 Enter' 提示")
	}

	// B. 關鍵測試：純 Enter
	time.Sleep(1 * time.Second)
	log.Println("⌨️  [Client]: 正在按下 'Enter' (空字串)...")
	sendMsg("")

	if waitFor("最新消息", 5*time.Second) {
		log.Println("✅ 成功通過 '純 Enter' 測試，看到最新消息！")
	} else {
		log.Println("❌ '純 Enter' 測試失敗，未看到後續畫面")
	}

	// C. 測試 refresh 崩潰 (模擬斷線)
	log.Println("🔄 正在模擬網頁 refresh (斷線並重新連線)...")
	conn.Close()
	time.Sleep(1 * time.Second)

	log.Println("🔌 重新連線...")
	conn2, _, err := websocket.DefaultDialer.Dial(u.String(), nil)
	if err == nil {
		log.Println("✅ 重新連線成功，伺服器未崩潰！")
		conn2.Close()
	} else {
		log.Fatalf("❌ 重新連線失敗，伺服器可能已崩潰: %v", err)
	}

	log.Println("✅ 整合測試執行完畢。")
}
