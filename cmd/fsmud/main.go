// cmd/webmud/main.go
package main

import (
	"flag"
	"fmt"
	"io/fs"
	"log"
	"net/http"
	"os"
	"strings"
	"time"

	"mudscript" // 導入根目錄 package 以取得 Assets
	"mudscript/driver"
	"mudscript/internal/p2p"
	"mudscript/internal/signaling"
	"mudscript/object"
)

func main() {
	hubURL := flag.String("hub", "wss://wade-fs-fsmud-hub.hf.space/ws", "Signaling hub URL (set to 'none' to run in isolation)")
	port := flag.String("port", "8080", "HTTP server port")
	flag.Parse()

	log.Println("正在初始化 WebMUD 伺服器 (Hybrid 模式)...")

	// 1. 準備 MUD 引擎配置
	config := driver.DriverConfig{
		MudLibPath:      "./mudlib",
		MasterFile:      "/master.c",
		HeartBeatTick:   0, 
		CleanUpInterval: 5 * time.Minute, // 🚀 新增：5分鐘執行一次 GC
		EmbeddedFS:      mudscript.Assets, 
	}

	// 2. 初始化 MUD 腳本引擎
	d := driver.New(config)
	
	if err := d.Start(); err != nil {
		panic(err)
	}
	log.Println("MUD 引擎啟動成功！")

	// 3. 初始化 WebSocket 與 P2P 信令中心
	hub := signaling.NewHub(d) 
	go hub.Run()

	// 🚀 新增：同步玩家名稱至信令中心
	d.OnUsernameUpdate = func(sid, newName string) {
		hub.UpdateClientUsername(sid, newName)
	}

	// 4. 🚀 P2P 整合核心：雙向連結驅動與信令系統
	
	// A. 連結 P2P -> MUD (接收訊息)
	d.OnP2PMessage = func(sender, content string) {
		log.Printf("🌌 [P2P] 收到來自 %s 的訊息: %s", sender, content)
		interstellar, err := d.LoadObject("/secure/interstellar_d.c")
		if err == nil && interstellar != nil {
			msgType := "chat"
			if strings.HasPrefix(sender, "SYSTEM") {
				msgType = "system"
			}
			// 🚀 關鍵：確保傳遞給 LPC 的參數數量與 receive_p2p_message(3) 完全一致
			d.CallFunction(interstellar, "receive_p2p_message", []object.Object{
				&object.String{Value: sender},
				&object.String{Value: content},
				&object.String{Value: msgType},
			})
		}
	}

	// B. 連結 MUD -> P2P (發送訊息)
	isRemoteHub := *hubURL != "" && *hubURL != "none"
	
	// 🚀 安全檢查：如果目前是在 Hugging Face 上執行且 URL 指向自己，則不連線 (避免重複)
	if os.Getenv("SPACE_ID") != "" && strings.Contains(*hubURL, os.Getenv("SPACE_ID")) {
		log.Println("ℹ️ 偵測到於雲端 Hub 執行，略過自我 P2P 連線以避免重複訊息。")
		isRemoteHub = false
	}

	if isRemoteHub {
		node := p2p.NewNode(d, *hubURL)
		
		d.P2PSendChat = func(sender, content string) {
			node.SendChat(sender, content)
		}

		node.Start()
		log.Println("🚀 P2P 節點已啟動，連接至:", *hubURL)
	} else {
		// 如果自己是信令中心，直接透過 hub 廣播
		d.P2PSendChat = func(sender, content string) {
			hub.BroadcastChat(sender, content)
		}
	}

	// 5. 設定 HTTP 與 WebSocket 路由
	http.HandleFunc("/ws", func(w http.ResponseWriter, r *http.Request) {
		signaling.HandleWS(hub, w, r)
	})

	// 🚀 混合模式網頁服務
	setupStaticServer()

	// 6. 啟動 Web 伺服器
	log.Printf("Web 伺服器監聽中 :%s\n", *port)
	err := http.ListenAndServe(":"+*port, nil)
	if err != nil {
		panic(err)
	}
}

func setupStaticServer() {
	diskPath := "./web/static"
	
	if info, err := os.Stat(diskPath); err == nil && info.IsDir() {
		log.Println("🌐 [WEB] 使用外部磁碟網頁檔案 (支援熱更新)")
		http.Handle("/", http.FileServer(http.Dir(diskPath)))
	} else {
		log.Println("📦 [WEB] 使用內建嵌入網頁檔案")
		subFS, err := fs.Sub(mudscript.Assets, "web/static")
		if err != nil {
			panic(fmt.Sprintf("無法開啟嵌入網頁目錄: %v", err))
		}
		http.Handle("/", http.FileServer(http.FS(subFS)))
	}
}
