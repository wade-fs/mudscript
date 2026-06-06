// cmd/test-fs/main.go
package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"
	"os/exec"
	"time"
)

func main() {
	// 1. 啟動 bin/fs 伺服器 (背景執行)
	log.Println("🚀 正在啟動 Legacy FS 伺服器進行測試...")
	cmd := exec.Command("./bin/fs")
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	if err := cmd.Start(); err != nil {
		log.Fatalf("無法啟動伺服器: %v", err)
	}
	defer func() {
		log.Println("🛑 正在關閉伺服器...")
		cmd.Process.Kill()
	}()

	// 2. 等待伺服器就緒
	time.Sleep(3 * time.Second)

	// 3. 建立 Telnet 連線
	log.Println("🔌 正在建立 Telnet 連線至 localhost:4000...")
	conn, err := net.Dial("tcp", "localhost:4000")
	if err != nil {
		log.Fatalf("連線失敗: %v", err)
	}
	defer conn.Close()

	// 啟動一個 Goroutine 來讀取伺服器回傳
	go func() {
		scanner := bufio.NewScanner(conn)
		for scanner.Scan() {
			fmt.Printf("🖥️  [Server]: %s\n", scanner.Text())
		}
	}()

	// 4. 模擬登入流程
	inputs := []string{
		"guest", // 輸入帳號
		"",      // 響應 "-- 請按 Enter 鍵繼續 --"
		"look",  // 執行 look 指令
		"go north", // 執行移動指令
		"go south", // 執行移動指令
		"go north", // 執行移動指令
		"who",   // 執行 who 指令
		"help",  // 執行 help 指令
	}

	for _, input := range inputs {
		time.Sleep(2 * time.Second)
		log.Printf("⌨️  [Client]: 正在輸入 '%s'...", input)
		_, err := fmt.Fprintf(conn, "%s\n", input)
		if err != nil {
			log.Fatalf("發送指令失敗: %v", err)
		}
	}

	// 最後多等一下看有沒有後續回應
	log.Println("⏳ 等待 5 秒觀察後續回應...")
	time.Sleep(5 * time.Second)
	log.Println("✅ 測試腳本執行完畢。")
}
