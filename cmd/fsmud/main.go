// cmd/webmud/main.go
package main

import (
	"flag"
	"fmt"
	"io/fs"
	"log"
	"net/http"
	"os"

	"mudscript" // 導入根目錄 package 以取得 Assets
	"mudscript/driver"
	"mudscript/internal/p2p"
	"mudscript/internal/signaling"
	"mudscript/object"
)

func main() {
	hubURL := flag.String("hub", "", "Signaling hub URL (e.g. ws://localhost:8080/ws)")
	port := flag.String("port", "8080", "HTTP server port")
	flag.Parse()

	log.Println("正在初始化 WebMUD 伺服器 (Hybrid 模式)...")

	// 1. 準備 MUD 引擎配置
	config := driver.DriverConfig{
		MudLibPath:    "./mudlib",
		MasterFile:    "/master.c",
		HeartBeatTick: 0, 
		EmbeddedFS:    mudscript.Assets, 
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
		interstellar, _ := d.LoadObject("/secure/interstellar_d.c")
		if interstellar != nil {
			d.CallFunction(interstellar, "receive_p2p_message", []object.Object{
				&object.String{Value: sender},
				&object.String{Value: content},
			})
		}
	}

	// B. 連結 MUD -> P2P (發送訊息)
	if *hubURL != "" {
		node := p2p.NewNode(d, *hubURL)
		
		d.P2PSendChat = func(sender, content string) {
			node.SendChat(sender, content)
		}

		if err := node.Start(); err != nil {
			log.Printf("⚠️ P2P 啟動失敗: %v", err)
		} else {
			log.Println("🚀 P2P 節點已啟動，連接至:", *hubURL)
		}
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
